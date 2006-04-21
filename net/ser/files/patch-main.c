
$FreeBSD$

--- main.c.orig
+++ main.c
@@ -251,6 +251,10 @@
    be default yes, good for trouble-shooting
 */
 int server_signature=1;
+/*
+ * Server's signature if different from default.
+ */
+char* server_name = 0;
 /* should ser try to locate outbound interface on multihomed
  * host? by default not -- too expensive
  */
@@ -350,6 +354,7 @@
 void cleanup(show_status)
 {
 	/*clean-up*/
+	setlogmask(LOG_UPTO(LOG_INFO));
 	if (mem_lock) 
 		shm_unlock(); /* hack: force-unlock the shared memory lock in case
 					 some process crashed and let it locked; this will 
