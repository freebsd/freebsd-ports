*** src/sipkrb5.c.orig	Thu May  7 11:58:42 2009
--- src/sipkrb5.c	Thu May  7 11:59:42 2009
***************
*** 35,41 ****
--- 35,46 ----
  #include <string.h>
  #include <errno.h>
  #include <ctype.h>
+ #ifdef __FreeBSD__
+ #include <com_err.h>
+ #else
  #include <et/com_err.h>
+ #endif
+ 
  
  #include "debug.h"
  #include "util.h"
