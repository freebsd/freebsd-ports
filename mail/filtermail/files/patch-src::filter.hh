--- src/filter.hh.orig	Sun Jan 25 21:56:42 2004
+++ src/filter.hh	Fri Mar 19 23:19:33 2004
@@ -21,8 +21,8 @@
 
 #include <string>
 extern "C" {
-#include <regex.h>
 #include <sys/types.h> 
+#include <regex.h>
 }
 
 // Filter modes
