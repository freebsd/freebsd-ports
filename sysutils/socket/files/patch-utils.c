*** utils.c.orig	Fri Feb 29 15:21:52 2008
--- utils.c	Fri Feb 29 15:23:26 2008
***************
*** 89,98 ****
--- 89,102 ----
  	  case SIGTTIN:
  	  case SIGSTOP:
  	  case SIGCONT:
  	    continue ;
  #endif
+ #ifdef SIGINFO
+ 	  case SIGINFO:
+ 	    continue ;
+ #endif
  #if !defined (SIGCHLD) && defined (SIGCLD)
  #define SIGCHLD SIGCLD
  #endif
  #ifdef SIGCHLD
  	  case SIGCHLD:


