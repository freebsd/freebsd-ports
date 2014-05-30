--- src/main-window.h.orig	2014-04-30 17:56:08.057123807 +0000
+++ src/main-window.h	2014-04-30 17:56:29.581127225 +0000
@@ -28,6 +28,8 @@
 #include <libnotify/notify.h>
 #endif
 
+#include <glib.h>
+
 #if GLIB_CHECK_VERSION(2, 32, 0)
 #include <gio/gio.h>
 #elif defined(HAVE_LIBNM_GLIB)
