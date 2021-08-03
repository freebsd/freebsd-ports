--- pan/gui/score-view-ui.cc.orig	2021-08-03 02:28:32 UTC
+++ pan/gui/score-view-ui.cc
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
 #include "pad.h"
 #include "score-add-ui.h"
