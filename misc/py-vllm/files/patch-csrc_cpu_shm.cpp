--- csrc/cpu/shm.cpp.orig	2026-11-02 08:07:02 UTC
+++ csrc/cpu/shm.cpp
@@ -9,6 +9,10 @@
   #include <atomic>
 #endif
 
+#ifndef MAP_POPULATE
+  #define MAP_POPULATE 0
+#endif
+
 namespace {
 #define MAX_SHM_RANK_NUM 8
 #define PER_THREAD_SHM_BUFFER_BYTES (4 * 1024 * 1024)
