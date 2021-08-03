--- pan/gui/actions.cc.orig	2021-08-03 02:20:11 UTC
+++ pan/gui/actions.cc
@@ -18,10 +18,8 @@
  */
 
 #include <config.h>
-extern "C" {
-  #include <glib/gi18n.h>
-  #include "gtk-compat.h"
-}
+#include <glib/gi18n.h>
+#include "gtk-compat.h"
 
 #include <pan/general/macros.h>
 #include <pan/general/debug.h>
