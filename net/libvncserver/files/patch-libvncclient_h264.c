--- libvncclient/h264.c.orig	2016-06-26 17:53:47 UTC
+++ libvncclient/h264.c
@@ -20,6 +20,10 @@
 #ifdef LIBVNCSERVER_CONFIG_LIBVA
 
 #include <X11/Xlib.h>
+#include <va/va_version.h>
+#if VA_CHECK_VERSION(0,39,2)
+#include <va/va_compat.h>
+#endif
 #include <va/va_x11.h>
 
 enum _slice_types {
