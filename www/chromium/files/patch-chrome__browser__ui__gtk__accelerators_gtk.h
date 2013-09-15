--- chrome/browser/ui/gtk/accelerators_gtk.h.orig	2013-09-13 13:12:50.000000000 -0400
+++ chrome/browser/ui/gtk/accelerators_gtk.h	2013-09-13 13:13:09.000000000 -0400
@@ -5,6 +5,8 @@
 #ifndef CHROME_BROWSER_UI_GTK_ACCELERATORS_GTK_H_
 #define CHROME_BROWSER_UI_GTK_ACCELERATORS_GTK_H_
 
+#include <vector>
+
 #include "base/containers/hash_tables.h"
 #include "ui/base/accelerators/accelerator.h"
 
