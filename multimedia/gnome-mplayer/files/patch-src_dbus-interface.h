--- src/dbus-interface.h.orig	2014-04-24 03:38:08 UTC
+++ src/dbus-interface.h
@@ -37,5 +37,5 @@
 #include <X11/extensions/scrnsaver.h>
 #endif
 
-gboolean screensaver_disabled;
+extern gboolean screensaver_disabled;
 gboolean dbus_hookup(gint windowid, gint controlid);
