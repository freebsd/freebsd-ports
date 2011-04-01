--- chrome/browser/ui/views/accessible_view_helper.h.orig	2011-01-26 10:30:51.000000000 +0100
+++ chrome/browser/ui/views/accessible_view_helper.h	2011-01-30 14:03:17.000000000 +0100
@@ -15,7 +15,7 @@
 #include "chrome/browser/accessibility_events.h"
 #include "gfx/native_widget_types.h"
 
-#if defined(OS_LINUX)
+#if defined(TOOLKIT_USES_GTK)
 #include "chrome/browser/ui/gtk/accessible_widget_helper_gtk.h"
 #endif
 
@@ -73,7 +73,7 @@
   std::string window_title_;
   std::vector<views::View*> managed_views_;
 
-#if defined(OS_LINUX)
+#if defined(TOOLKIT_USES_GTK)
   scoped_ptr<AccessibleWidgetHelper> widget_helper_;
 #endif
 
