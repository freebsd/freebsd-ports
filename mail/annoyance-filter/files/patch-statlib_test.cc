--- statlib_test.cc.orig	Thu Sep 25 02:02:10 2003
+++ statlib_test.cc	Fri Jan  2 02:51:57 2004
@@ -28,7 +28,7 @@
 #include <unistd.h> 
 #endif
 #else
-#include "getopt.h"     
+#include <getopt.h>
 #endif
 #include "statlib.h"        
 
