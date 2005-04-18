*** libnal/proto_fd.c.ori      Wed Apr 13 21:07:10 2005
--- libnal/proto_fd.c  Wed Apr 13 21:55:12 2005
***************
*** 26,31 ****
--- 26,38 ----
  #include "nal_internal.h"
  #include "ctrl_fd.h"
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
