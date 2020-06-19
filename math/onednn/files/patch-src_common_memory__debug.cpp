--- src/common/memory_debug.cpp.orig	2020-06-19 06:42:33 UTC
+++ src/common/memory_debug.cpp
@@ -21,7 +21,7 @@
 #include <windows.h>
 #endif
 
-#if defined __linux__ || defined __APPLE__
+#if defined __linux__ || defined __APPLE__ || defined __FreeBSD__
 #include <unistd.h>
 #include <sys/mman.h>
 #endif
