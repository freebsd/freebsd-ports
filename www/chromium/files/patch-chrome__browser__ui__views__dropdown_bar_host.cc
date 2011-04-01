--- chrome/browser/ui/views/dropdown_bar_host.cc.orig	2011-01-26 10:30:51.000000000 +0100
+++ chrome/browser/ui/views/dropdown_bar_host.cc	2011-01-30 14:07:11.000000000 +0100
@@ -19,7 +19,7 @@
 
 #if defined(OS_WIN)
 #include "base/win/scoped_gdi_object.h"
-#elif defined(OS_LINUX)
+#elif defined(TOOLKIT_GTK)
 #include "ui/base/gtk/scoped_handle_gtk.h"
 #endif
 
@@ -27,7 +27,7 @@
 
 #if defined(OS_WIN)
 typedef base::win::ScopedRegion ScopedPlatformRegion;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_FREEBSD)
 typedef ui::ScopedRegion ScopedPlatformRegion;
 #endif
 
