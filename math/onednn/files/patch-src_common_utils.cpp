--- src/common/utils.cpp.orig	2020-06-19 06:53:00 UTC
+++ src/common/utils.cpp
@@ -19,7 +19,7 @@
 #include <windows.h>
 #endif
 
-#if defined __linux__ || defined __APPLE__
+#if defined __linux__ || defined __APPLE__ || defined __FreeBSD__
 #include <unistd.h>
 #endif
 
