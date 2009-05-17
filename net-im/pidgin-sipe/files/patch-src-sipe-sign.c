*** src/sipe-sign.c.orig	Thu May  7 11:58:37 2009
--- src/sipe-sign.c	Thu May  7 11:59:03 2009
***************
*** 26,32 ****
--- 26,36 ----
  #include <errno.h>
  #include <ctype.h>
  #ifndef _WIN32
+ #ifdef __FreeBSD__
+ #include <com_err.h>
+ #else
  #include <et/com_err.h>
+ #endif
  #else
  #include <protocols/zephyr/com_err.h>
  #include "internal.h"
