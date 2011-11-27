
$FreeBSD$

--- tvcapture.h.orig
+++ tvcapture.h
@@ -34,8 +34,14 @@
 #include <X11/Intrinsic.h>
 #ifdef __NetBSD__
 # include <dev/ic/bt8xx.h>
+#endif
+#ifdef __FreeBSD__
+#include <osreldate.h>
+#if __FreeBSD_version > 500000
+#include <dev/bktr/ioctl_meteor.h>
 #else
-# include <machine/ioctl_meteor.h>
+#include <machine/ioctl_meteor.h>
+#endif
 #endif
 #include "tvtypes.h"
 
