*** mimedefang-multiplexor.c	Sat Jun 15 01:44:53 2002
--- mimedefang-multiplexor.c	Sat Jun 15 18:42:55 2002
***************
*** 13,19 ****
  ***********************************************************************/
  
  static char const RCSID[] =
! "$Id: mimedefang-multiplexor.c,v 1.71 2002/06/14 17:08:24 dfs Exp $";
  
  #include "config.h"
  #include "event_tcp.h"
--- 13,19 ----
  ***********************************************************************/
  
  static char const RCSID[] =
! "$Id: mimedefang-multiplexor.c,v 1.72 2002/06/15 01:12:25 dfs Exp $";
  
  #include "config.h"
  #include "event_tcp.h"
***************
*** 1989,1999 ****
--- 1989,2010 ----
  	as *= 1024;
  	lim.rlim_cur = as;
  	lim.rlim_max = as;
+ #ifdef RLIMIT_AS
  	n = setrlimit(RLIMIT_AS, &lim);
  	if (n < 0) {
  	    syslog(LOG_WARNING, "setrlimit(RLIMIT_AS, %lu) failed: %m",
  		   as);
  	}
+ #endif
+ 
+ #ifdef RLIMIT_DATA
+ 	n = setrlimit(RLIMIT_DATA, &lim);
+ 	if (n < 0) {
+ 		syslog(LOG_WARNING, "setrlimit(RLIMIT_DATA, %lu) failed: %m",
+ 		   as);
+ 	}
+ #endif
+ 
      }
  }
  
