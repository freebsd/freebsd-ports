--- src/DirReadJob.cpp.orig	2024-01-18 23:06:51 UTC
+++ src/DirReadJob.cpp
@@ -7,6 +7,7 @@
  */
 
 
+#include <unistd.h>	// access()
 #include <dirent.h>     // struct dirent
 #include <fcntl.h>	// AT_ constants (fstatat() flags)
 
