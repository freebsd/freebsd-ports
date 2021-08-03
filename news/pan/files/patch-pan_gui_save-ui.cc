--- pan/gui/save-ui.cc.orig	2021-08-03 02:27:18 UTC
+++ pan/gui/save-ui.cc
@@ -18,10 +18,8 @@
  */
 
 #include <config.h>
-extern "C" {
-  #include <glib/gi18n.h>
-  #include "gtk-compat.h"
-}
+#include <glib/gi18n.h>
+#include "gtk-compat.h"
 #include <pan/general/debug.h>
 #include <pan/general/macros.h>
 #include <pan/icons/pan-pixbufs.h>
