--- src/Preferences.cpp.orig	Tue Mar 18 19:22:47 2003
+++ src/Preferences.cpp	Sun Mar 23 00:58:06 2003
@@ -22,6 +22,10 @@
 #include <config.h>
 #endif // HAVE_CONFIG_H
 
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#include <sys/param.h>
+#endif
+
 #include "wintypes.h"
 #include "Preferences.h"
 #include <time.h>
@@ -41,7 +45,11 @@
 #include <sys/stat.h>
 #include <sys/types.h>
 
+#if (defined(BSD) && (BSD >= 199103))
+#define MAX_PATH MAXPATHLEN
+#else
 #define MAX_PATH 2048
+#endif
 
 extern int sprintf(char *__restrict __s,__const char*__restrict __format,...) __attribute__ ((__format__ (__printf__, 2,3)));
 
