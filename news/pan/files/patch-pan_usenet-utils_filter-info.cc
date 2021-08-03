--- pan/usenet-utils/filter-info.cc.orig	2021-08-03 01:59:02 UTC
+++ pan/usenet-utils/filter-info.cc
@@ -18,10 +18,8 @@
  */
 
 #include <config.h>
-extern "C" {
-  #include <glib.h>
-  #include <glib/gi18n.h>
-}
+#include <glib.h>
+#include <glib/gi18n.h>
 #include <pan/general/macros.h>
 #include "filter-info.h"
 
