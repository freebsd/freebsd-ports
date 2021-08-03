--- pan/gui/server-ui.cc.orig	2021-08-03 02:28:55 UTC
+++ pan/gui/server-ui.cc
@@ -21,11 +21,9 @@
 #include <cstdlib>
 #include <cstring>
 #include <climits>
-extern "C" {
-  #include <glib.h>
-  #include <glib/gi18n.h>
-  #include "gtk-compat.h"
-}
+#include <glib.h>
+#include <glib/gi18n.h>
+#include "gtk-compat.h"
 
 #include <pan/icons/pan-pixbufs.h>
 #include <pan/general/file-util.h>
