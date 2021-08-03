--- pan/gui/progress-view.cc.orig	2021-08-03 02:21:46 UTC
+++ pan/gui/progress-view.cc
@@ -18,9 +18,7 @@
  */
 
 #include <config.h>
-extern "C" {
-  #include "gtk-compat.h"
-}
+#include "gtk-compat.h"
 #include <pan/general/string-view.h>
 #include <pan/usenet-utils/mime-utils.h>
 #include "progress-view.h"
