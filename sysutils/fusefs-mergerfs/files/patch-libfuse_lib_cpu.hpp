--- libfuse/lib/cpu.hpp.orig	2024-02-29 20:41:22 UTC
+++ libfuse/lib/cpu.hpp
@@ -5,8 +5,12 @@
 #endif
 
 #include <pthread.h>
+#ifdef __FreeBSD__
+#define sched_getaffinity(pid, size, set) 0
+#define pthread_setaffinity_np(thread, size, set) 0
+#else
 #include <sched.h>
-
+#endif
 #include <set>
 #include <unordered_map>
 #include <vector>
