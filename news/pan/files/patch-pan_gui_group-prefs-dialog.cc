--- pan/gui/group-prefs-dialog.cc.orig	2021-08-03 02:20:45 UTC
+++ pan/gui/group-prefs-dialog.cc
@@ -18,14 +18,12 @@
  */
 
 #include <config.h>
-extern "C" {
-  #include <glib/gi18n.h>
-  #include <glib.h>
-  #include "gtk-compat.h"
+#include <glib/gi18n.h>
+#include <glib.h>
+#include "gtk-compat.h"
 #ifdef HAVE_GTKSPELL
-  #include <enchant/enchant.h>
+#include <enchant/enchant.h>
 #endif
-}
 #include <pan/general/debug.h>
 #include <pan/general/macros.h>
 #include <pan/data/data.h>
