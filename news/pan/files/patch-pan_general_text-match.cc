--- pan/general/text-match.cc.orig	2021-08-03 01:57:31 UTC
+++ pan/general/text-match.cc
@@ -18,11 +18,9 @@
  */
 
 #include <config.h>
-extern "C" {
-  #include <ctype.h>
-  #include <glib.h>
-  #include <glib/gi18n.h>
-}
+#include <ctype.h>
+#include <glib.h>
+#include <glib/gi18n.h>
 #include "debug.h"
 #include "log.h"
 #include "text-match.h"
