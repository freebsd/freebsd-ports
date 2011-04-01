--- ./chrome/browser/ui/views/tabs/dragged_tab_view.h.orig	2010-12-16 02:11:56.000000000 +0100
+++ ./chrome/browser/ui/views/tabs/dragged_tab_view.h	2010-12-20 20:15:08.000000000 +0100
@@ -14,7 +14,7 @@
 namespace views {
 #if defined(OS_WIN)
 class WidgetWin;
-#elif defined(OS_LINUX)
+#elif defined(TOOLKIT_GTK)
 class WidgetGtk;
 #endif
 }
@@ -71,7 +71,7 @@
   // The window that contains the DraggedTabView.
 #if defined(OS_WIN)
   scoped_ptr<views::WidgetWin> container_;
-#elif defined(OS_LINUX)
+#elif defined(TOOLKIT_GTK)
   scoped_ptr<views::WidgetGtk> container_;
 #endif
 
