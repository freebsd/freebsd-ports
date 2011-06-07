--- chrome/browser/ui/views/fullscreen_exit_bubble.cc.orig	2011-05-06 12:03:37.000000000 +0300
+++ chrome/browser/ui/views/fullscreen_exit_bubble.cc	2011-06-04 00:31:52.427403621 +0300
@@ -19,7 +19,7 @@
 #if defined(OS_WIN)
 #include "ui/base/l10n/l10n_util_win.h"
 #include "views/widget/widget_win.h"
-#elif defined(OS_LINUX)
+#elif defined(TOOLKIT_GTK)
 #include "views/widget/widget_gtk.h"
 #endif
 
