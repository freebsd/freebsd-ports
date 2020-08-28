Parital backport of:
	https://github.com/jvirkki/dupd/commit/f137a38b948f5f5710cf2c7bfc7e9a70fba662f4

--- src/stats.h.orig	2020-08-28 20:17:51 UTC
+++ src/stats.h
@@ -28,7 +28,7 @@
 #define ROUND2 1
 #define MAX_HASHER_THREADS 2
 
-pthread_mutex_t stats_lock;
+extern pthread_mutex_t stats_lock;
 
 extern int stats_sets_processed[ROUNDS];
 extern int stats_sets_dup_done[ROUNDS];
