--- src/CFile.cpp.orig	Sun Mar 23 00:13:37 2003
+++ src/CFile.cpp	Sun Mar 23 00:16:34 2003
@@ -53,6 +53,10 @@
     #define   NOMCX
 #endif
 
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#include <sys/param.h>
+#endif
+
 #elif (defined(__UNIX__) || defined(__GNUWIN32__))
     #include  <unistd.h>
     #ifdef __GNUWIN32__
@@ -116,7 +120,11 @@
 #endif
 
 #ifndef MAX_PATH
-    #define MAX_PATH 512
+#	if (defined(BSD) && (BSD >= 199103))
+#		define MAX_PATH MAXPATHLEN
+#	else
+#		define MAX_PATH 512
+#	endif
 #endif
 
 // some broken compilers don't have 3rd argument in open() and creat()
