*** list.c.orig	Sun Apr  1 15:19:28 2001
--- list.c	Sun Apr  1 15:19:39 2001
***************
*** 1,6 ****
--- 1,8 ----
  #include "list.h"
  #include <stdlib.h>
+ #ifndef __FreeBSD__
  #include <malloc.h>
+ #endif
  #include <string.h>
  
  
