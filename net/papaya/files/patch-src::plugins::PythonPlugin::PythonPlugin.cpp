--- src/plugins/PythonPlugin/PythonPlugin.cpp.orig	Fri Jan  9 15:18:10 2004
+++ src/plugins/PythonPlugin/PythonPlugin.cpp	Fri Jan  9 15:18:14 2004
@@ -12,7 +12,7 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <string.h>
-#include <malloc.h>
+#include <stdlib.h>
 #include <regex.h>
 
 #ifdef WIN32
