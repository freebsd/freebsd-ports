--- mdnsd/mdns.c.orig	2026-03-19 21:39:49 UTC
+++ mdnsd/mdns.c
@@ -45,6 +45,9 @@
 struct question_tree		 question_tree;
 struct cache_tree		 cache_tree;
 
+pg_q pg_queue;
+pge_q pge_queue;
+
 /*
  * RR cache
  */
