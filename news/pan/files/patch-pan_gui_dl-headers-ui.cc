--- pan/gui/dl-headers-ui.cc.orig	2021-08-03 02:25:00 UTC
+++ pan/gui/dl-headers-ui.cc
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
 #include <pan/general/macros.h>
 #include <pan/tasks/queue.h>
 #include <pan/tasks/task-xover.h>
