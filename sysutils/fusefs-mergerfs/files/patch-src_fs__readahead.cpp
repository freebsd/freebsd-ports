--- src/fs_readahead.cpp.orig	2024-02-29 20:41:22 UTC
+++ src/fs_readahead.cpp
@@ -25,7 +25,11 @@
 #include <fstream>
 #include <string>
 
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#else
 #include <sys/sysmacros.h>
+#endif
 
 namespace l
 {
