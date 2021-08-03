--- pan/tasks/task-groups.cc.orig	2021-08-03 02:04:54 UTC
+++ pan/tasks/task-groups.cc
@@ -19,10 +19,8 @@
 
 #include <config.h>
 #include <cassert>
-extern "C" {
-  #include <glib/gi18n.h>
-  #include <stdlib.h>
-}
+#include <glib/gi18n.h>
+#include <stdlib.h>
 #include <pan/general/debug.h>
 #include <pan/general/macros.h>
 #include <pan/general/messages.h>
