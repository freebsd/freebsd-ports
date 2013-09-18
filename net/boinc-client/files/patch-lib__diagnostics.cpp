--- ./lib/diagnostics.cpp.orig	2013-07-24 15:13:29.000000000 +0000
+++ ./lib/diagnostics.cpp	2013-09-17 21:40:56.000000000 +0000
@@ -41,6 +41,7 @@
 #include <cstdarg>
 #include <cstdlib>
 #include <unistd.h>
+#include <time.h>
 #endif
 
 #ifdef _USING_FCGI_
