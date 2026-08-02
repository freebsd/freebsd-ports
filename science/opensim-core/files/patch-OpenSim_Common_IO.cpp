--- OpenSim/Common/IO.cpp.orig	2026-06-18 22:26:24 UTC
+++ OpenSim/Common/IO.cpp
@@ -37,7 +37,7 @@
 #include <string>
 #include <sstream>
 #include <time.h>
-#if defined(__linux__) || defined(__APPLE__)
+#if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
     #include <sys/stat.h>
     #include <sys/types.h>
 #elif defined(_MSC_VER)
