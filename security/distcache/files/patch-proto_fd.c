*** libnal/proto_fd.c.ori       Wed Apr 13 19:34:07 2005
--- libnal/proto_fd.c   Wed Apr 13 21:51:20 2005
***************
*** 24,29 ****
--- 24,36 ----
  #include <libnal/nal.h>
  #include "nal_internal.h"
  #include <libsys/post.h>
+ #ifdef __FreeBSD__
+ #if __FreeBSD_version >= 502010
+ #include <sys/limits.h>
+ #else
+ #include <machine/limits.h>
+ #endif
+ #endif /* __FreeBSD__ */

  /**************************/
  /* predeclare our vtables */
