--- ./chrome/browser/ui/views/extensions/extension_popup.cc.orig	2010-12-16 02:11:56.000000000 +0100
+++ ./chrome/browser/ui/views/extensions/extension_popup.cc	2010-12-20 20:15:08.000000000 +0100
@@ -25,7 +25,7 @@
 #include "views/window/window.h"
 
 
-#if defined(OS_LINUX)
+#if defined(TOOLKIT_GTK)
 #include "views/widget/widget_gtk.h"
 #endif
 
@@ -108,7 +108,7 @@
   // The bubble chrome requires a separate window, so construct it here.
   if (BUBBLE_CHROME == popup_chrome_) {
     gfx::NativeView native_window = frame->GetNativeView();
-#if defined(OS_LINUX)
+#if defined(TOOLKIT_GTK)
     border_widget_ = new views::WidgetGtk(views::WidgetGtk::TYPE_WINDOW);
     static_cast<views::WidgetGtk*>(border_widget_)->MakeTransparent();
     static_cast<views::WidgetGtk*>(border_widget_)->make_transient_to_parent();
