#if 0 /*
#	This program is easy to compile. For example the following ways:
#		$ sh identd.c
#		$ sh identd.c -g -DDEBUG
#		$ sh identd.c -s -DXXXMULTI
#		$ CC=cc sh identd.c
#		$ CC=egcs sh identd.c -s -fomit-frame-pointer

NAME=`basename $0 .c`
[ x`uname` = xSunOS ] && L="-lsocket -lnsl" || L=
[ x$1 = x ] && set -- -s -O2
CMDLINE="${CC:-gcc} -Wall $@ -o $NAME $NAME.c $L"
echo $CMDLINE; exec $CMDLINE; exit -1

# */
#endif
/*
 * $Id: identd.c,v 1.7 2002/09/29 07:50:20 too Stab $
 *
 * Author: Tomi Ollila <too@iki.fi>
 *
 * Created: Sat Nov 25 15:34:07 1995 too
 * Last modified: Sun Sep 29 10:48:42 2002 too
 *
 * This program is standalone 'fake' ident daemon. This program does
 * not fork() but is configured to handle up to 20 concurrent connections.
 * Since one connection should not last long, if all 20 connections are
 * in use, the next connection will close the oldest connection data
 * has been read. This way this program is not very vulnerable to so
 * called `denial of service' attack, thus making this ideal "identd"
 * to be used in a firewall.
 *
 * Program takes one (or many) arguments, which if exist, determines the
 * `user' name(s) that is returned for successful ident query.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * HISTORY
 * $Log: identd.c,v $
 *
 * Revision 1.7  2002/09/29 07:50:20  too
 *   No longer chops up to IDSTR_MAX chars, but uses "%.*s" to limit length;
 *	now works also when XXXMULTI defined.
 *   Back-hacked self-compilable trick, with more tricks to avoid compiler
 *	warnings.
 *   Removed own define of FD_SETSIZE altogether;
 *	systems has it small to begin with.
 *   Line '415' (or whatever that is now) fixed. () -> (void) in func def.
 *   Some fine tuning.
 *   Thanks to Cristian for his patches.
 *
 * Revision 1.6.1  2002-09-28 12:30:29 +0200  cii
 *   + added defines for IDSTR_MAX, IDENT_SUBSTR, IDSTR_BUFLEN and IDSTR_MAX
 *     (length limit on the id-string)
 *   + program arg 1 chopped after IDSTR_MAX characters (when applicable);
 *     reason is:
 *       - if the program is called with a relativelly long string as arg 1
 *         (tested with about 400 chars), a segfault occurs due to an internal
 *         buffer overflow (buffer space reserved for id-string is 128 chars,
 *         but never verified)
 *       - it may trigger buffer overflows in clients
 *   + put a proper comment at the top of the file
 *   + sorted out FD_SETSIZE (on Linux it's already defined)
 *       - moved it down below all the includes
 *   + added time.h include
 *   + added some short comments
 *   + conditionals '{', '}' enclosed
 *   + variable index -> idx in function closeOldest (killed a warning)
 *   + splitted multiple statements on a singel line
 *   + splitted long lines
 *   + prototypes ending in '()' -> '(void)'; changed by protoize
 *   + corrected most warnings, but "function declaration isn't a prototype"
 *     which still occurs on line: 415
 *   + added IDENT_PORT
 *   + added IDENT_SUBSTR
 *
 * Revision 1.6  2002/07/31 16:25:20  too
 * Now works when started as root (in Linux). Stupid me, tested
 * only starting as an ordinary loser.
 *
 * Revision 1.5  2002/07/29 14:02:42  too
 * Added possibility to have multible reply users, one (pseudo)randomly
 * chosen at each time.
 *
 * Revision 1.4  2001/02/09 08:45:42  too
 * Now GID is also changed to nobody/nogroup.
 *
 * Revision 1.3  2000/06/07 05:55:44  too
 * Fixed some Solaris compilation "bugs".
 * Changed LOG_PERROR to LOG_CONS
 *
 * Revision 1.2  1999/07/30 04:08:42  too
 * Added printing version string (and exit) with `-V' command line option.
 *
 * Revision 1.1  1999/04/21 17:23:20  too
 * - Writes process id to /var/run/identd.pid.
 * - Changes (effective) user id to `nobody' after initialization
 *	(binding socket etc.).
 * - Ignores some signals (HUP and PIPE).
 * - Handles some signals that aborts by default. The handler function
 *	tries to get rid of the pidfile.
 *
 * Revision 0.9b 1999/04/15 20:45:12  too
 * Not so much spaghetti anymore. Added documentation and more replies.
 *
 * Revision 0.9  1999/04/12 18:30:00  too
 * Version for unix systems. Standalone, supports 20 concurrent connections.
 * The code is quite a spaghetti. But that does not matter.
 *
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>
#include <syslog.h>

#include <pwd.h>
#include <netdb.h>

#include <sys/syslog.h>
#include <sys/types.h>
#include <sys/time.h>
#include <time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>


#define IDENT_PORT	113
#define IDENT_SUBSTR	": USERID : UNIX :"
#define MAXCONNS	20
#define MAXIDLETIME	45
#define IDSTR_BUFLEN	128 /*could be dropped down to 64 if tight in memory */

/*
 * format string is: "%d, %d " IDENT_SUBSTR " %.*s\r\n"
 * %d is max 999999999 (allowed by this identd, 
 */
#define IDSTR_MAX	(IDSTR_BUFLEN - 1) - \
	9 - 2 - 9 - 1 - (sizeof IDENT_SUBSTR - 1) - 1 - 2

#ifndef DEBUG
#define FCS		2	/* First Connection Socket */
#define TRACE(x);
#else
#define FCS		4
#define TRACE(x)	printf x
#endif

/* descriptors when debugging:
 *  0 = server socket
 *  1 = standard output (debugging output)
 *  2 = standard error
 *  3 = syslog fd (hopefully -- otherwise this won't work)
 *  4 - 4 + MAXCONNS = connection sockets
 *
 * descriptors when not debugging
 *  0 = server socket
 *  1 = syslog fd (hopefully -- otherwise this won't work)
 *  2 = connection socket after detached from tty. standard error before that
 *  3 - 2 + MAXCONNS = rest connection sockets
 */

/*
 * FD of the connection is always the index of the connection structure
 * in `conns' array + FCS
 */
struct {
  char		buf[20];
  int		len;
  time_t	lasttime;
} conns[MAXCONNS];


/*
 * To support multible usernames that can be replied by this fake identd
 * define `XXXMULTI' in compilation command line. This doesn't look guite
 * pretty, but alternatives looks even uglier.
 * XXX NOTE: multi currently only slightly tested XXXX.
 */
#ifdef XXXMULTI
#define IU_IN_STRUCT char ** identuserlist; int identusers
#define SET_IU(s, c) do { G.identuserlist = &(s); G.identusers = c; } while (0)
#define IU_IN_USAGESTR "[identuser [identuser2...]]"
#else
#define IU_IN_STRUCT char * identuser
#define SET_IU(s, c) G.identuser = (s)
#define IU_IN_USAGESTR "[identuser]"
#endif

/* When using global variables, bind those at least to a structure. */
struct {
  IU_IN_STRUCT;
  fd_set	readfds;
  int		conncnt;
} G;

static const char rcs_id[] =
/* */ "$Id: identd.c,v 1.7 2002/09/29 07:50:20 too Stab $";


/*
 * Prototypes
 */
static void reply(int s, char * buf);
static void replyError(int s, char * buf);
static const char * strerrno(void);

const int one = 1;
char *	  nobodystr = "nobody";

/* a more general name would be `movefd',but we are only moving sockets here */
static inline void movesocket(int from, int to)
{
  TRACE(("movesocket(from = %d, to = %d)\n", from, to));
  dup2(from, to);
  close(from);
}

/*
 * inetbind() must always return 0 or value < 0.
 */
static int inetbind(int port)
{
  int			s;
  struct sockaddr_in	addr = { 0 };
  int			len = sizeof addr;
  
  close(0);
  
  if ((s = socket(AF_INET, SOCK_STREAM, 0)) < 0)
  {
      syslog(LOG_CRIT, "cannot create server socket: %s.", strerrno());
      return -1;
  }
  
  setsockopt(s, SOL_SOCKET, SO_REUSEADDR, &one, sizeof one);
  
  addr.sin_family = AF_INET;
  addr.sin_port = htons(port);
  
  if (bind(s, (struct sockaddr *)&addr, len) < 0)
  {
      syslog(LOG_CRIT, "cannot bind() server socket: %s.", strerrno());
      return -1;
  }
  
  if (listen(s, 5) < 0)
  {
      syslog(LOG_CRIT, "cannot listen() server socket: %s.", strerrno());
      return -1;
  }
  
  if (s != 0)
  {
      movesocket(s, 0);
  }
  
  return 0;
}

static void deleteConn(int s)
{
  int i = s - FCS;
  
  TRACE(("deleteConn(): socket %d, conncnt %d\n", s, G.conncnt));
  
  close(s);
  
  G.conncnt--;
  
  /*
   * Most of the time there is 0 connections. Most often that there
   * is connections, there is just one connection. When this one connection
   * closes, i == G.conncnt = 0 -> no copying.
   * When there is more than one connection, the oldest connections closes
   * earlier on average. When this happens, the code below starts copying
   * the connection structure w/ highest index to the place which which is
   * just deleted. This means that the connection structures are no longer
   * in chronological order. I'd quess this means that when there is more
   * than 1 connection, on average every other connection structure needs
   * to be copied over the time all these connections are deleted.
   */
  if (i != G.conncnt)
  {
      memcpy(&conns[i], &conns[G.conncnt], sizeof conns[0]);
      movesocket(G.conncnt + FCS, s);
  }
  
  TRACE(("Clearing fd %d, readfds now 0x%x\n\n",
	 G.conncnt + FCS, *(int *)&G.readfds));
  
  FD_CLR(G.conncnt + FCS, &G.readfds);
}

static int closeOldest(void)
{
  time_t min = conns[0].lasttime;
  int	 idx = 0;
  int	 i;
  
  for (i = 1; i < MAXCONNS; i++)
  {
      if (conns[i].lasttime < min)
      {
	  idx = i;
      }
  }
  TRACE(("closeOldest(): index %d, socket %d\n", idx, idx + FCS));
  
  replyError(idx + FCS, "X-SERVER-TOO-BUSY");
  close(idx + FCS);
  
  return idx;
}


static inline int checkInput(char * buf, int len, int l)
{
  int	i;
  
  for (i = len; i < len + l; i++)
  {
      if (buf[i] == '\n')
      {
	  return 1;
      }
  }
  
  return 0;
}


static int getport(void)
{
  struct servent * se;
  
  if ((se = getservbyname("identd", "tcp")) == NULL)
  {
      return IDENT_PORT;
  }
  else
  {
      return se->s_port;
  }
}

static const char * strerrno()
{
  return sys_errlist[errno];
}

/* here we trust no-one in this program overflows our data buffer. */
static void fdprintf(int fd, char * format, ...)
{
  va_list	ap;
  char		buf[IDSTR_BUFLEN];
  
  va_start(ap, format);
  vsprintf(buf, format, ap);
  va_end(ap);
  
  write(fd, buf, strlen(buf));
}


#ifndef DEBUG
static void godaemon(void)
{
  switch(fork())
  {
  case -1:
    exit(-1);
    
  case 0:
    close(1);
    close(2);
    setsid();
    break;
    
  default:
    exit(0);
  }
}
#endif

#define PIDFILE "/var/run/identd.pid"

static void delpidfile(void)
{
  /*
   * Usually nobody has no write/delete access to directory /var/run/
   * therefore if file cannot be deleted, it is truncated
   */
  if (unlink(PIDFILE) < 0)
  {
      close(open(PIDFILE, O_WRONLY|O_CREAT|O_TRUNC, 0644));
  }
}

static void handlexitsigs(void)
{
  delpidfile();
  exit(0);
}

static void writepid(uid_t nobody, uid_t nogrp)
     /* May succeed. If not, won't care. */
{
  int fd = open(PIDFILE, O_WRONLY|O_CREAT|O_TRUNC, 0664);
  
  if (fd < 0)
  {
      return;
  }
  
  fdprintf(fd, "%d\n", getpid());
  fchown(fd, nobody, nogrp);
  close(fd);
  
  signal(SIGTERM, (void(*)(int))handlexitsigs);
  signal(SIGINT, (void(*)(int))handlexitsigs);
  signal(SIGQUIT, (void(*)(int))handlexitsigs);
  /* should this handle ILL, ... (see signal(7)) */
}

/* parses the `rcs_id' string for version information and prints the info. */
static void printversion(char nameterm)
{
  struct {
    const char * p;
    int		 l;

  } s[4] = { { 0 } };

  int		i;
  const char *	p;
  
  for (i = 0, p = rcs_id; *p && i < 4 ; i++)
  {
      while (*p != ' ' && *p != '\0')
      {
	  p++;
      }
      if (*p++ == ' ' && *p != '\0')
      {
	  s[i].p = p;
      }
  }
  
  if (s[0].p)
  {
      p = s[0].p;
      while (*p != nameterm && *p != ' ')
      {
	  p++;
      }
      s[0].l = p - s[0].p;
  }
  else
  {
      s[0].p = "unknown";
      s[0].l = 7;
  }
  
  for (i = 1; i < 3; i++)
  {
      if (s[i+1].p)
      {
	  s[i].l = s[i+1].p - s[i].p - 1;
      }
      else
      {
	  s[i].p = "unknown"; s[i].l = 7;
      }
  }
  
  fdprintf(1, "%.*s %.*s (%.*s)\n",
	   s[0].l, s[0].p, /**/ s[1].l, s[1].p, /**/ s[2].l, s[2].p);
}

int main(int argc, char * argv[])
{
  uid_t nobody, nogrp;
  
  memset(conns, 0, sizeof conns);
  memset(&G, 0, sizeof G);
  FD_ZERO(&G.readfds);
  FD_SET(0, &G.readfds);
  
  if (argv[1])
  {
      if (argv[1][0] == '-')
      {
	  if (argv[1][1] == 'V')
	  {
	      printversion('.');
	      return 0;
	  }
	  else
	  {
	      fdprintf(2, "%s: invalid option -- %c\n", argv[0], argv[1][1]);
	      fdprintf(2, "Usage: %s [-V] " IU_IN_USAGESTR "\n", argv[0]);
	      return 1;
	  }
      }
      else
      {
	  SET_IU(argv[1], argc - 1);
      }
  }
  else
  {
      SET_IU(nobodystr, 1);
  }
  
  
#ifndef DEBUG
  close(1); /* not debugging, openlog() hopefully uses fd 1. */
#else
  close(3); /* debugging, TRACE uses fd 1, openlog() hopefully fd 3 */
#endif
  
  openlog("identd", LOG_CONS, LOG_DAEMON);
  
  {
      struct passwd * pw = getpwnam(nobodystr);
      
      if (pw)
      {
	  nobody = pw->pw_uid;
	  nogrp = pw->pw_gid;
      }
      else
      {
	  syslog(LOG_CRIT, "Cannot find user `nobody': %s", strerrno());
	  return -1;
      }
  }
  
  if (inetbind(getport()) < 0)
  {
      return -1;
  }
  
  /* */
  {
      int			 i;
      
      for (i = FCS; i < MAXCONNS + FCS; i++)
      {
	  close(i);
      }
  }
  
#ifdef DEBUG
#ifndef LOG_PERROR
#define LOG_PERROR 0
#endif
  openlog("identd", LOG_PERROR, LOG_DAEMON);
#else /* not DEBUG */
  godaemon();
  openlog("identd", 0, LOG_DAEMON);
  close(2);
  signal(SIGHUP, SIG_IGN);
#endif /* DEBUG */
  
  signal(SIGPIPE, SIG_IGN); /* connection closed when writing (raises ???) */
  
  writepid(nobody, nogrp);
  
  setegid(nogrp); setgid(nogrp); setuid(nobody); seteuid(nobody);
  
  {
      int i;
      
      for (i = 0; i < 4; i++)
      {
	  char *	id = (char)NULL;
	  unsigned int	rv = 0;
	  
	  switch (i)
	  {
	  case 0:
	    rv = (unsigned int)getegid();
	    id = "egid";
	    break;
	  case 1:
	    rv = (unsigned int)getgid();
	    id = "gid";
	    break;
	  case 2:
	    rv = (unsigned int)geteuid();
	    id = "euid";
	    break;
	  case 3:
	    rv = (unsigned int)getuid();
	    id = "uid";
	    break;
	  }
	  
	  if (rv == 0)
	  {
	      syslog(LOG_ERR,
		     "Can not drop all root privileges (%s) !!! %s !!!",
		     id, strerrno());
	      delpidfile();
	      return -1;
	  }
      }
  }
  
  while (2)
  {
      fd_set		rfds = G.readfds;
      struct timeval	tv = { 15, 0 };
      int		i;
      int		tim = time(NULL);
      
      TRACE(("calling select(): n = %d, rfds = 0x%x\n\n",
	     G.conncnt + FCS, *(int *)&rfds));
      
      select(G.conncnt + FCS, &rfds, NULL, NULL, G.conncnt? &tv: NULL);
      
      for (i = G.conncnt - 1; i >= 0; i--)
      {
	  int s = i + FCS;
	  
	  if (FD_ISSET(s, &rfds))
	  {
	      char *		buf = conns[i].buf;
	      unsigned int	len = conns[i].len;
	      unsigned int	l;
	      
	      TRACE(("data socket fd_isset %d\n", s));
	      
	      if ((int)(l = read(s, buf + len, sizeof conns[0].buf - len)) > 0)
	      {
		  if (checkInput(buf, len, l))
		  {
		      reply(s, buf);
		      goto deleteconn;
		  }
		  else if (len + l >= sizeof conns[0].buf)
		  {
		      replyError(s, "X-INVALID-REQUEST");
		      goto deleteconn;
		  }
		  else
		  {
		      conns[i].len += l;
		  }
	      }
	      else
	      {
		  goto deleteconn;
	      }
	      
	      conns[i].lasttime = tim;
	      continue;
	      
	  deleteconn:
	      deleteConn(s);
	  }
	  else
	  {
	      /* implement as time_after() in linux kernel sources ... */
	      if (conns[i].lasttime + MAXIDLETIME <= tim)
	      {
		  replyError(s, "X-TIMEOUT");
		  deleteConn(s);
	      }
	  }
      }
      
      if (FD_ISSET(0, &rfds))
      {
	  int s = accept(0, NULL, 0);
	  
	  TRACE(("server socket fd_isset, %d accepted\n", s));
	  
	  if (s < 0)
	  {
	      if (errno != EINTR) /* EINTR */
	      {
		  syslog(LOG_ERR, "accept: %s", strerrno());
	      }
	  }
	  else
	  {
	      if (G.conncnt == MAXCONNS)
	      {
		  i = closeOldest();
	      }
	      else
	      {
		  i = G.conncnt++;
	      }
	      
	      if (s != i + FCS)
	      {
		  movesocket(s, i + FCS);
	      }
	      
	      FD_SET(i + FCS, &G.readfds);
	      
	      conns[i].len = 0;
	      conns[i].lasttime = time(NULL);
	  }
      }
  }
}

static int parseAddrs(char * ptr, int * myaddr, int * heraddr);

static void replyError(int s, char * buf)
{
  fdprintf(s, "0, 0 : ERROR : %s\r\n", buf);
}

static void reply(int s, char * buf)
{
  int myaddr, heraddr;
  
  myaddr = heraddr = 0;
  
  if (parseAddrs(buf, &myaddr, &heraddr))
  {
      replyError(s, "X-INVALID-REQUEST");
  }
  else
  {
      fdprintf(s, "%d, %d " IDENT_SUBSTR " %.*s\r\n",
	       myaddr, heraddr, IDSTR_MAX,
#ifdef XXXMULTI
	       G.identuserlist[random() % G.identusers]
#else
       	       G.identuser
#endif
	       );
  }
}


static int chmatch(char c, char * chars)
{
  while (*chars)
  {
    if (c == *chars)
    {
	return 1;
    }
    else
    {
	chars++;
    }
  }

  return 0;
}

static int skipchars(char ** p, char * chars)
{
  while (chmatch(**p, chars))
  {
      (*p)++;
  }

  if (**p == '\r' || **p == '\n')
  {
      return -1;
  }

  return 0;
}

static int parseAddrs(char * ptr, int * myaddr, int * heraddr)
{
  /* parse <port-on-server> , <port-on-client> */

  if (skipchars(&ptr, " \t") ||
      (*myaddr = atoi(ptr)) <= 0 ||
      skipchars(&ptr, "1234567890") ||
      skipchars(&ptr, " \t,") ||
      (*heraddr = atoi(ptr)) <= 0)
  {
      return -1;
  }

  return 0;
}


/*
 * Variables for Emacs
 *
 * Local variables:
 * mode: c
 * c-file-style: "gnu"
 * c-file-offsets: ( (substatement-open . 0) (statement-block-intro . ++) )
 * tab-width: 8
 * compile-command: "sh identd.c"
 * End:
 */

/* EOF */
