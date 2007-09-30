--- src/mailsync_main.cc.orig	Sun Sep 30 15:39:52 2007
+++ src/mailsync_main.cc	Sun Sep 30 15:39:56 2007
@@ -68,7 +68,7 @@
   int success;
   bool& debug = options.debug;
 
-#include "linkage.c"
+#include "linkage.h"
 
   //
   // Parse arguments, read config file, choose operation mode
