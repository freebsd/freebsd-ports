--- pan/tasks/task-post.cc.orig	2021-08-03 02:05:17 UTC
+++ pan/tasks/task-post.cc
@@ -18,9 +18,7 @@
  */
 
 #include <config.h>
-extern "C" {
-  #include <glib/gi18n.h>
-}
+#include <glib/gi18n.h>
 #include "task-post.h"
 #include <pan/general/debug.h>
 #include <pan/general/log.h>
