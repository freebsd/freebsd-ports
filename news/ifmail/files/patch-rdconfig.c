*** iflib/rdconfig.c.orig	Tue Oct 19 11:27:29 2004
--- iflib/rdconfig.c	Tue Oct 19 11:29:47 2004
***************
*** 5,10 ****
--- 5,11 ----
  #include <sys/types.h>
  #include <sys/stat.h>
  #include <time.h>
+ #include <unistd.h>
  #include "xutil.h"
  #include "lutil.h"
  #include "ftn.h"
***************
*** 402,409 ****
  			verbose=setverbose(arg);
  			break;
  
! 	case 'I':	configname=arg;
! 			break;
  
  	default:	return 1; /* unrecognized option */
  
--- 403,415 ----
  			verbose=setverbose(arg);
  			break;
  
! 	case 'I':
! 		if (issetugid())
! 			fprintf(stderr,
! 		    "readconfig: -I option ignored while running as set-user-ID\n");
! 		else
! 			configname=arg;
! 		break;
  
  	default:	return 1; /* unrecognized option */
  
