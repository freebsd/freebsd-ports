*** src/core/sipe-utils.c.orig	Wed Oct 20 12:44:43 2010
--- src/core/sipe-utils.c	Wed Oct 20 12:45:02 2010
***************
*** 36,41 ****
--- 36,44 ----
  #ifdef __APPLE__
  #include <sys/socket.h>
  #endif
+ #ifdef __FreeBSD__
+ #include <sys/socket.h>
+ #endif
  #include <unistd.h>
  #include <net/if.h>
  #include <sys/types.h>
