--- statlib_test.cc.orig	2004-08-04 12:28:53 UTC
+++ statlib_test.cc
@@ -28,7 +28,7 @@ using namespace std;
 #include <unistd.h> 
 #endif
 #else
-#include "getopt.h"     
+#include <getopt.h>
 #endif
 #include "statlib.h"        
 
