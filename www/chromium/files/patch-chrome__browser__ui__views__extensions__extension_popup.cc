--- chrome/browser/ui/views/extensions/extension_popup.cc.orig	2011-05-06 12:03:37.000000000 +0300
+++ chrome/browser/ui/views/extensions/extension_popup.cc	2011-06-04 00:14:39.536404067 +0300
@@ -23,7 +23,7 @@
 #include "views/widget/root_view.h"
 #include "views/window/window.h"
 
-#if defined(OS_LINUX)
+#if defined(TOOLKIT_GTK)
 #include "views/widget/widget_gtk.h"
 #endif
 
