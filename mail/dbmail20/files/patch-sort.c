--- sort/sort.c.orig	Tue Mar 15 00:54:00 2005
+++ sort/sort.c	Mon Apr 11 13:46:46 2005
@@ -58,7 +58,7 @@
  *
  * Then do it!
  * */
-dsn_class_t sort_and_deliver(u64_t msgidnr,
+sort_result_t sort_and_deliver(u64_t msgidnr,
 		const char *header UNUSED, 
 		u64_t headersize UNUSED, 
 		u64_t totalmsgsize, 
