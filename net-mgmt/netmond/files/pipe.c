/*
 *	Copyright (c) 1999-2002 Rinet Corp., Novosibirsk, Russia
 *      partial (c) vfom@narod.ru 
 *
 * Redistribution and use in source forms, with and without modification,
 * are permitted provided that this entire comment appears intact.
 *
 * THIS SOURCE CODE IS PROVIDED ``AS IS'' WITHOUT ANY WARRANTIES OF ANY KIND.
 */

#ifdef	HAVE_CONFIG_H
#include <config.h>
#endif

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <syslog.h>
#include <errno.h>
#ifdef	HAVE_DMALLOC_H
#include <dmalloc.h>
#else
#include "malloc.h"
#endif
#include "assert.h"

#include "netmon.h"
#include "regex.h"

extern int errno;
extern CONFIG *cf;                     /* current configuration */

static int pipe_execfile __P ((char *, char *,pid_t *, OBJECT *));

void
pipe_start(method)
	METHOD *method;
{
	SESSION *sd = method->sd;
	OBJECT *target = sd->owner;
	int tmpval;

	/* sanity check */
	if (!sd) return;

	tcp_stop(method); /* stop the method if still running */
	if ((method->sd)->pid > 0) { kill((method->sd)->pid, SIGTERM); }
	sd->pid = -1;

	/* open stream socket near before TCP session */
	if ((sd->sock = pipe_execfile(method->when, method->argument, &(sd->pid), target)) < 0) {
		tcp_close(errno, sd, 0);
		return;
	}

	/* turn on non-blocking I/O before connecting */
	if (set_socket_async(sd->sock, TRUE) < 0) {
		tcp_close(errno, sd, 0);
		if ((method->sd)->pid > 0) { kill((method->sd)->pid, SIGTERM); }
		return;
	}

	/* timeout and retries for connection */
	sd->timeout = method->timeout * 1000000L; /* make miscroseconds */
	sd->retries = method->retries;
	sd->connect = tcp_connect;	/* `awaiting' connection */
	
	if ((tmpval = session_start(sd, NULL)) != 0) {
		dprintf(("pipe_start(%s/%s): reqid=%d\n",
			 sd->owner->name, method->name, tmpval));
//report(LOG_INFO, "pipe_start(%s/%s): reqid=%d\n",
//			 sd->owner->name, method->name, tmpval);
	}
}

int
pipe_init(target, method)
	OBJECT *target;
	METHOD *method;
{
	SESSION template;

	dprintf(("pipe_init(%s/%s)\n", target->name, method->name));
//	report(LOG_INFO,"pipe_init(%s/%s)\n", target->name, method->name);

	if (method->sd)
		session_free(method->sd);

	memset(&template, 0, sizeof(template));
	template.owner = target;
	template.method = method;
	template.sock = -1;	/* not yet opened */
	template.pid = -1;	
	template.timeout = method->timeout * 1000000L; /* make microseconds */
	template.retries = method->retries;
	template.connect = tcp_connect;
	template.send = tcp_send;
	template.recv = tcp_recv;
	template.read = tcp_close;

	if ((method->sd = session_create(&template)) == NULL) {
		errno = ENOMEM;
		return -1;
	}

	return 0;
}

#define	MAX_ARGS	50
int
pipe_execfile(file, args, p_pid, target)
	char *file, *args;
	pid_t *p_pid;
	OBJECT *target;
{
	sigset_t sigmask;
	int ac = 0, fildes[2];
	char *av[MAX_ARGS+2];
	extern char **environ;
	pid_t	pid;

	dprintf(("pipe_execfile: %s %s\n", file, args ? args : "null"));
//	report(LOG_INFO,"pipe_execfile: %s %s\n", file, args ? args : "null");

	if (socketpair(PF_LOCAL, SOCK_STREAM, 0, fildes) < 0) {
		report(LOG_ERR, "socketpair: %m");
		return(-1);
	}

	if (*file != '/') {
		av[ac++] = "sh";
		av[ac++] = "-c";
		av[ac++] = file;
#ifdef	_PATH_BSHELL
		file = _PATH_BSHELL;
#else
		file = "/bin/sh";
#endif
	} else	av[ac++] = strippath(file);

	ac += make_argv(args, (char ***) &av[ac], MAX_ARGS);
	av[ac] = NULL;

	switch (pid=vfork()) {
	case -1:
		report(LOG_ERR, "fork: %m");
		close(fildes[0]);
		close(fildes[1]);
		return(-1);
	case 0:		/* child */
		if (fcntl(fildes[0], F_SETFD, 0) < 0) {
    		    report(LOG_ERR," fcntl (F_SETFD, 0): %m");
	    	    _exit(127);
		}
		if (fildes[0] != 0) {
			dup2(fildes[0], 0);
			close(fildes[0]);
		}
		dup2(0, 1);
		dup2(0, 2);

		/* child would be terminated by signals */
		sigprocmask(SIG_SETMASK, NULL, &sigmask);
		sigprocmask(SIG_UNBLOCK, &sigmask, NULL);
		close(netstate_sock);

		/* make session leader to be able killpg() latter */
		setsid();

		if ( cf->chrootdir) {
		    if ( chroot( cf->chrootdir ) < 0 ) {
			report(LOG_ERR, "chroot %s: %s", cf->chrootdir,strerror(*(__error())) );
			_exit(127);
		    }
		}
		if ( setgid(cf->gid) < 0 ) {
		    report(LOG_ERR, "setgid %s[%d]: %s", cf->groupname, cf->gid, strerror(*(__error())) );
		    _exit(127);
		}			
		if ( (cf->uid != 0) & (setuid(cf->uid) < 0) ) {
		    report(LOG_ERR, "setuid %s[%d]: %s", cf->username, cf->uid, strerror(*(__error())) );
		    _exit(127);
		}		
		
    		setenv ("OBJECT_NAME",target->name,1 );
    		setenv ("OBJECT_ADDRESS",target->address,1 );
		if (target->srcaddress) 
		    setenv ("OBJECT_SRC_ADDRESS",target->srcaddress,1 );
		if (target->datadir) 
		    setenv ("OBJECT_DATADIR",target->datadir,1 );
		execve(file, av, environ);
		report(LOG_ERR, "execve %s: %m", file);
		_exit(127);
	}
	/* parent */
	if ( p_pid != NULL ) { *p_pid = pid; };
	close(fildes[0]);
	return(fildes[1]);
}

void
when_stop(method)
	METHOD *method;
{
//	session_stop(method->sd, 1);
}

void
when_start(method)
	METHOD *method;
{
	SESSION *sd = method->sd;
	OBJECT *target = sd->owner;
	TIMEVAL tv_now;
	
	char *diag, buf[4096];
	int tmpval, matched;

	/* sanity check */
	if (!sd) return;
	
	sd->sock=-1;

	/* calculate condition */
	insert_variables(buf, sizeof(buf), method->when, TYPE_OBJECT, target);
	matched = (calculate(buf) ? 1 : 0);
//	report(LOG_WARNING, "when_start EVAL: '%s' %d %s %d",buf,matched,target->name,sd->tv_sum.tv_sec);
	diag = "OK" ;
	if ( matched ) {
	    gettimeofday(&tv_now,NULL);
	    if ( (u_int64_t)sd->tv_sum.tv_sec != 0 ) {
		if ( ( (u_int64_t)(tv_now.tv_sec) - (u_int64_t)(sd->tv_sum.tv_sec) ) > method->timeout ) {
		    insert_variables(buf, sizeof(buf), method->when_fmt, TYPE_OBJECT, target);
		    diag = buf;		
		}	    	    
	    } else {
		sd->tv_sum.tv_sec = tv_now.tv_sec;
		matched = 0;
	    }
	} else {
	    sd->tv_sum.tv_sec=0;
	}
//	report(LOG_WARNING, "when_start DIAG: '%s' %d %d",diag,matched,sd->tv_sum.tv_sec);

	dump_var_list(target->var_list);
	method_finished(target, method, diag, !matched);
}

int
when_init(target, method)
	OBJECT *target;
	METHOD *method;
{
	SESSION template;
	dprintf(("when_init(%s/%s)\n", target->name, method->name));

	if (method->sd)
		session_free(method->sd);

	memset(&template, 0, sizeof(template));
	template.owner = target;
	template.method = method;
	template.sock = -1; /* never used socket */
	if ((method->sd = session_create(&template)) == NULL) {
		errno = ENOMEM;
		return -1;
	}
	return 0;
}
