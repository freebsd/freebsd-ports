--- mozilla/MyportalProtocolHandler.cpp.orig	Thu Nov  7 01:40:46 2002
+++ mozilla/MyportalProtocolHandler.cpp	Thu Nov  7 01:40:55 2002
@@ -26,7 +26,7 @@
 
 extern "C" {
 extern char *realpath (__const char *__restrict __name,
-                       char *__restrict __resolved) __THROW;
+                       char *__restrict __resolved);
 };
 
 #include <stdlib.h>
