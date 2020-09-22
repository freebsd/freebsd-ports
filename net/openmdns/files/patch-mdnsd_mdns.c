--- mdnsd/mdns.c.orig	2017-03-10 09:24:12 UTC
+++ mdnsd/mdns.c
@@ -45,6 +45,9 @@ extern struct mdnsd_conf	*conf;
 struct question_tree		 question_tree;
 struct cache_tree		 cache_tree;
 
+pg_q pg_queue;
+pge_q pge_queue;
+
 /*
  * RR cache
  */
