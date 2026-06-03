--- csrc/cpu/shm.cpp.orig	2026-04-07 17:37:32 UTC
+++ csrc/cpu/shm.cpp
@@ -2,6 +2,9 @@
 
 #include <fcntl.h>
 #include <sys/mman.h>
+#ifndef MAP_POPULATE
+#  define MAP_POPULATE 0
+#endif
 #include <sys/stat.h>
 #include <unistd.h>
 
