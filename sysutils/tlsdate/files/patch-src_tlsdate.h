--- src/tlsdate.h.orig	2020-09-20 12:00:20 UTC
+++ src/tlsdate.h
@@ -188,7 +188,7 @@ struct state
   int exitting;
 };
 
-char timestamp_path[PATH_MAX];
+extern char timestamp_path[PATH_MAX];
 
 int is_sane_time (time_t ts);
 int load_disk_timestamp (const char *path, time_t * t);
