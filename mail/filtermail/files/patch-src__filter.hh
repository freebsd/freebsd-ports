--- src/filter.hh.orig	2016-06-05 09:28:35 UTC
+++ src/filter.hh
@@ -21,8 +21,8 @@
 
 #include <string>
 extern "C" {
-#include <regex.h>
 #include <sys/types.h> 
+#include <regex.h>
 }
 
 // Filter modes
