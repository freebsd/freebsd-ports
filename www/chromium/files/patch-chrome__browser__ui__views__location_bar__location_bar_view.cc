--- ./chrome/browser/ui/views/location_bar/location_bar_view.cc.orig	2010-12-16 02:11:56.000000000 +0100
+++ ./chrome/browser/ui/views/location_bar/location_bar_view.cc	2010-12-20 20:15:08.000000000 +0100
@@ -4,7 +4,7 @@
 
 #include "chrome/browser/views/location_bar/location_bar_view.h"
 
-#if defined(OS_LINUX)
+#if defined(TOOLKIT_USES_GTK)
 #include <gtk/gtk.h>
 #endif
 
