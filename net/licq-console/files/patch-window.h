--- src/window.h.orig	Thu Sep 30 03:51:03 2004
+++ src/window.h	Wed Oct 13 14:19:58 2004
@@ -3,7 +3,7 @@
 
 #include <iostream>
 extern "C" {
-#include <cdk.h>
+#include <cdk/cdk.h>
 }
 
 #define COLOR_YELLOW_BLUE COLOR_YELLOW + 8
