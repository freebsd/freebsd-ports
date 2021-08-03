--- pan/gui/score-add-ui.cc.orig	2021-08-03 02:28:07 UTC
+++ pan/gui/score-add-ui.cc
@@ -20,9 +20,7 @@
 #include <config.h>
 #include <cassert>
 #include <climits>
-extern "C" {
-  #include <glib/gi18n.h>
-}
+#include <glib/gi18n.h>
 #include <pan/general/debug.h>
 #include <pan/general/text-match.h>
 #include "hig.h"
