--- src/chrono_cosimulation/ChHostInfo.h.orig	2019-05-05 02:19:44 UTC
+++ src/chrono_cosimulation/ChHostInfo.h
@@ -46,7 +46,7 @@
 #if (defined _WIN32)
 #define WINDOWS_XP
 #endif
-#if (defined(__linux__) || defined(__APPLE__))
+#if (defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__DragonFly__) || defined(__APPLE__))
 #define UNIX
 #endif
 
