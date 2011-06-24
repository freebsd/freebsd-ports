--- conn.h.orig	2011-06-24 15:38:41.000000000 +0400
+++ conn.h	2011-06-24 15:39:11.000000000 +0400
@@ -72,9 +72,9 @@
 
     job out_job;
     int out_job_sent;
-    struct job reserved_jobs; /* doubly-linked list header */
     tube use;
     struct ms watch;
+    struct job reserved_jobs; /* doubly-linked list header */
 };
 
 conn make_conn(int fd, char start_state, tube use, tube watch);
