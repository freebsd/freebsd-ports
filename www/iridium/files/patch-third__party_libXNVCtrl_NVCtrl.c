--- third_party/libXNVCtrl/NVCtrl.c.orig	2017-12-30 16:57:06.449527000 +0100
+++ third_party/libXNVCtrl/NVCtrl.c	2017-12-30 16:57:57.055972000 +0100
@@ -27,10 +27,6 @@
  * libXNVCtrl library properly protects the Display connection.
  */
 
-#if !defined(XTHREADS)
-#define XTHREADS
-#endif /* XTHREADS */
-
 #define NEED_EVENTS
 #define NEED_REPLIES
 #include <stdint.h>
@@ -39,6 +35,11 @@
 #include <X11/Xutil.h>
 #include <X11/extensions/Xext.h>
 #include <X11/extensions/extutil.h>
+
+#if !defined(XTHREADS)
+#define XTHREADS
+#endif /* XTHREADS */
+
 #include "NVCtrlLib.h"
 #include "nv_control.h"
 
