--- src/runtime/shared_mem.cc.orig	2023-04-30 05:51:10 UTC
+++ src/runtime/shared_mem.cc
@@ -6,6 +6,7 @@
 #ifndef _WIN32
 #include <fcntl.h>
 #include <sys/mman.h>
+#include <sys/stat.h>
 #include <unistd.h>
 #endif
 #include <dgl/runtime/shared_mem.h>
