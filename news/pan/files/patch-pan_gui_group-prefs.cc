--- pan/gui/group-prefs.cc.orig	2021-08-03 02:25:25 UTC
+++ pan/gui/group-prefs.cc
@@ -17,12 +17,10 @@
  *
  */
 
-extern "C" {
-  #include <config.h>
-  #include <sys/types.h> // chmod
-  #include <sys/stat.h> // chmod
-  #include <glib.h>
-}
+#include <config.h>
+#include <sys/types.h> // chmod
+#include <sys/stat.h> // chmod
+#include <glib.h>
 #include <iostream>
 #include <fstream>
 #include <pan/general/file-util.h>
