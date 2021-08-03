--- pan/gui/header-pane.cc.orig	2021-08-03 02:19:33 UTC
+++ pan/gui/header-pane.cc
@@ -17,12 +17,10 @@
  *
  */
 
-extern "C" {
-  #include <config.h>
-  #include <glib/gi18n.h>
-  #include "gtk-compat.h"
-  #include "gtk-compat.h"
-}
+#include <config.h>
+#include <glib/gi18n.h>
+#include "gtk-compat.h"
+#include "gtk-compat.h"
 #include <cctype>
 #include <cmath>
 #include <algorithm>
