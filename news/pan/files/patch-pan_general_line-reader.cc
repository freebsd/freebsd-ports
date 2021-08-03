--- pan/general/line-reader.cc.orig	2021-08-03 01:56:04 UTC
+++ pan/general/line-reader.cc
@@ -1,9 +1,7 @@
 #include <config.h>
 #include <cstdio>
 #include <cstdlib>
-extern "C"{ 
-  #include <glib/gi18n.h>
-}
+#include <glib/gi18n.h>
 #include <cerrno>
 #include "file-util.h"
 #include "line-reader.h"
