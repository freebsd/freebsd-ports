--- pan/data-impl/data-impl.cc.orig	2021-08-03 02:10:47 UTC
+++ pan/data-impl/data-impl.cc
@@ -22,10 +22,8 @@
 **************/
 
 #include <config.h>
-extern "C" {
-  #include <glib/gi18n.h>
-  #include <glib.h> // for g_build_filename
-}
+#include <glib/gi18n.h>
+#include <glib.h> // for g_build_filename
 #include <pan/general/debug.h>
 #include <pan/general/file-util.h>
 #include <pan/general/log.h>
