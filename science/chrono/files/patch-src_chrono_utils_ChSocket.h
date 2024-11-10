--- src/chrono/utils/ChSocket.h.orig	2024-11-10 05:46:37 UTC
+++ src/chrono/utils/ChSocket.h
@@ -19,7 +19,7 @@
 #ifndef CHSOCKET_H
 #define CHSOCKET_H
 
-#if (defined(__linux__) || defined(__APPLE__))
+#if (defined(__linux__) || defined(__FreeBSD__) || defined(__APPLE__))
     #define UNIX
 #endif
 
