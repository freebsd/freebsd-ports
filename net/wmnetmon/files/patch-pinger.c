*** pinger.c.orig	Sun Apr  1 15:21:08 2001
--- pinger.c	Sun Apr  1 15:21:22 2001
***************
*** 14,20 ****
--- 14,22 ----
  #include <netdb.h>
  #include <errno.h>
  #include <stdlib.h>
+ #ifndef __FreeBSD__
  #include <malloc.h>
+ #endif
  #include <unistd.h>
  #include "list.h"
  #include "config.h"
