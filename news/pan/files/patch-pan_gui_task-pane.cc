--- pan/gui/task-pane.cc.orig	2021-08-03 02:29:17 UTC
+++ pan/gui/task-pane.cc
@@ -18,11 +18,9 @@
  */
 
 #include <config.h>
-extern "C" {
-  #include <glib.h>
-  #include <glib/gi18n.h>
-  #include "gtk-compat.h"
-}
+#include <glib.h>
+#include <glib/gi18n.h>
+#include "gtk-compat.h"
 #include <pan/general/e-util.h>
 #include <pan/general/debug.h>
 #include <pan/general/file-util.h>
