--- server.c.orig	Wed Aug 24 13:35:38 2005
+++ server.c	Tue Sep 13 22:21:59 2005
@@ -119,7 +119,7 @@
   
  	trace(TRACE_DEBUG, "StartServer(): children created, starting main service loop");
  	while (!GeneralStopRequested) {
-		if (db_connect() != 0) {
+		if (db_check_connection() != 0) {
 			
 			if (! stopped) 
 				manage_stop_children();
@@ -128,12 +128,11 @@
 			sleep(10);
 			
 		} else {
-			if (stopped) 
+			if (stopped) {
+				manage_restart_children();
 				stopped=0;
- 			
-			db_disconnect();
+			}
 
-			manage_restart_children();
 			manage_spare_children();
 
 			sleep(1);
