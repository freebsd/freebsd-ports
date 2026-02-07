--- server/http-tx-mgr.c.orig	2023-11-29 21:44:30 UTC
+++ server/http-tx-mgr.c
@@ -28,7 +28,7 @@
 #define USER_AGENT_OS "Apple OS X"
 #endif
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__OpenBSD__)
 #define USER_AGENT_OS "Linux"
 #endif
 
