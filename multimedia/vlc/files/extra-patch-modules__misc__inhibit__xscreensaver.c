 --- ./modules/misc/inhibit/xscreensaver.c.ORIG	2010-04-13 02:22:27.000000000 +0200
 +++ ./modules/misc/inhibit/xscreensaver.c	2010-11-20 10:28:58.000000000 +0100
 @@ -39,7 +39,6 @@
  #include <sys/wait.h>
  #include <fcntl.h>
  #include <signal.h>
 -#include <spawn.h>
  
  /*****************************************************************************
   * Local prototypes
 @@ -53,13 +52,8 @@
  struct vlc_inhibit_sys
  {
      vlc_timer_t timer;
 -    posix_spawn_file_actions_t actions;
 -    posix_spawnattr_t attr;
 -    int nullfd;
  };
  
 -extern char **environ;
 -
  /*****************************************************************************
   * Module descriptor
   *****************************************************************************/
 @@ -88,21 +82,6 @@
      }
      p_ih->inhibit = Inhibit;
  
 -    int fd = vlc_open ("/dev/null", O_WRONLY);
 -    posix_spawn_file_actions_init (&p_sys->actions);
 -    if (fd != -1)
 -    {
 -        posix_spawn_file_actions_adddup2 (&p_sys->actions, fd, 1);
 -        posix_spawn_file_actions_adddup2 (&p_sys->actions, fd, 2);
 -        posix_spawn_file_actions_addclose (&p_sys->actions, fd);
 -    }
 -    p_sys->nullfd = fd;
 -
 -    sigset_t set;
 -    posix_spawnattr_init (&p_sys->attr);
 -    sigemptyset (&set);
 -    posix_spawnattr_setsigmask (&p_sys->attr, &set);
 -   
      return VLC_SUCCESS;
  }
  
 @@ -115,10 +94,6 @@
      vlc_inhibit_sys_t *p_sys = p_ih->p_sys;
  
      vlc_timer_destroy( p_sys->timer );
 -    if (p_sys->nullfd != -1)
 -        close (p_sys->nullfd);
 -    posix_spawnattr_destroy (&p_sys->attr);
 -    posix_spawn_file_actions_destroy (&p_sys->actions);
      free( p_sys );
  }
  
 @@ -131,15 +106,33 @@
  /*****************************************************************************
   * Execute: Spawns a process using execv()
   *****************************************************************************/
 -static void Execute (vlc_inhibit_t *p_ih, const char *const *argv)
 +static void Execute( vlc_inhibit_t *p_ih, const char *const *ppsz_args )
  {
 -    vlc_inhibit_sys_t *p_sys = p_ih->p_sys;
 -    pid_t pid;
 -
 -    if (posix_spawnp (&pid, argv[0], &p_sys->actions, &p_sys->attr,
 -                      (char **)argv, environ) == 0)
 +    pid_t pid = fork();
 +    switch( pid )
      {
 -        while (waitpid (pid, NULL, 0) != pid);
 +        case 0:     /* we're the child */
 +        {
 +            sigset_t set;
 +            sigemptyset (&set);
 +            pthread_sigmask (SIG_SETMASK, &set, NULL);
 +
 +            /* We don't want output */
 +            if( ( freopen( "/dev/null", "w", stdout ) != NULL )
 +             && ( freopen( "/dev/null", "w", stderr ) != NULL ) )
 +                execv( ppsz_args[0] , (char *const *)ppsz_args );
 +            /* If the file we want to execute doesn't exist we exit() */
 +            exit( EXIT_FAILURE );
 +        }
 +        case -1:    /* we're the error */
 +            msg_Dbg( p_ih, "Couldn't fork() while launching %s",
 +                     ppsz_args[0] );
 +            break;
 +        default:    /* we're the parent */
 +            /* Wait for the child to exit.
 +             * We will not deadlock because we ran "/bin/sh &" */
 +            while( waitpid( pid, NULL, 0 ) != pid);
 +            break;
      }
  }
  
