--- a/linux_v4l2.c
+++ b/linux_v4l2.c
@@ -47,8 +47,6 @@ __FBSDID("$FreeBSD$");
 #endif
 
 #include <compat/linux/linux_ioctl.h>
-#include <compat/linux/linux_videodev.h>
-#include <compat/linux/linux_videodev_compat.h>
 
 #include "linux_v4l2_ioctl.h"
 #include "linux_videodev2.h"
@@ -71,14 +69,14 @@ linux_v4l2_modevent(module_t mod __unuse
 }
 
 static moduledata_t v4l2_mod = {
-	"linux_v4l2",
+	"linux_v4l2wrapper",
 	linux_v4l2_modevent,
 	0
 };
 
-DECLARE_MODULE(linux_v4l2, v4l2_mod, SI_SUB_SYSCALLS, SI_ORDER_ANY);
-MODULE_VERSION(linux_v4l2, 1);
-MODULE_DEPEND(linux_v4l2, linux, 1, 1, 1);
+DECLARE_MODULE(linux_v4l2wrapper, v4l2_mod, SI_SUB_SYSCALLS, SI_ORDER_ANY);
+MODULE_VERSION(linux_v4l2wrapper, 1);
+MODULE_DEPEND(linux_v4l2wrapper, linux, 1, 1, 1);
 
 static int
 linux_to_bsd_v4l2_standard(struct l_v4l2_standard *lvstd, struct v4l2_standard *vstd)
