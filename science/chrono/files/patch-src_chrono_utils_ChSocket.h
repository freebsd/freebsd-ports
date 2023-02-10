--- src/chrono/utils/ChSocket.h.orig	2023-01-27 07:56:29 UTC
+++ src/chrono/utils/ChSocket.h
@@ -21,7 +21,7 @@
 #if (defined _WIN32)
     #define WINDOWS_XP
 #endif
-#if (defined(__linux__) || defined(__APPLE__))
+#if (defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__))
     #define UNIX
 #endif
 
