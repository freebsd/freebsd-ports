--- pan/tasks/nntp.cc.orig	2021-08-03 02:06:18 UTC
+++ pan/tasks/nntp.cc
@@ -22,10 +22,8 @@
 #include <cstdarg>
 #include <cstdlib> // abort, atoi, strtoul
 #include <cstdio> // snprintf
-extern "C" {
-  #include <glib.h>
-  #include <glib/gi18n.h>
-}
+#include <glib.h>
+#include <glib/gi18n.h>
 #include <pan/general/debug.h>
 #include <pan/general/log.h>
 #include <pan/general/messages.h>
