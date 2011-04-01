--- ./chrome/browser/ui/views/info_bubble.h.orig	2010-12-16 02:11:56.000000000 +0100
+++ ./chrome/browser/ui/views/info_bubble.h	2010-12-20 20:15:08.000000000 +0100
@@ -14,7 +14,7 @@
 
 #if defined(OS_WIN)
 #include "views/widget/widget_win.h"
-#elif defined(OS_LINUX)
+#elif defined(TOOLKIT_GTK)
 #include "views/widget/widget_gtk.h"
 #endif
 
@@ -178,7 +178,7 @@
 class InfoBubble
 #if defined(OS_WIN)
     : public views::WidgetWin,
-#elif defined(OS_LINUX)
+#elif defined(TOOLKIT_GTK)
     : public views::WidgetGtk,
 #endif
       public views::AcceleratorTarget,
@@ -252,7 +252,7 @@
 #if defined(OS_WIN)
   // Overridden from WidgetWin:
   virtual void OnActivate(UINT action, BOOL minimized, HWND window);
-#elif defined(OS_LINUX)
+#elif defined(TOOLKIT_GTK)
   // Overridden from WidgetGtk:
   virtual void IsActiveChanged();
 #endif
@@ -260,7 +260,7 @@
 #if defined(OS_WIN)
   // The window used to render the padding, border and arrow.
   BorderWidget* border_;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_FREEBSD)
   // The view displaying the border.
   BorderContents* border_contents_;
 #endif
