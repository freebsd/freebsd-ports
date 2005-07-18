Index: server.c
===================================================================
--- server.c	(revision 1600)
+++ server.c	(revision 1758)
@@ -119,9 +119,15 @@
  	alarm(10);
   
  	trace(TRACE_DEBUG, "StartServer(): children created, starting main service loop");
- 	while (!GeneralStopRequested) 
- 		manage_restart_children();
-   
+ 	while (!GeneralStopRequested) {
+		if (db_connect() != 0) {
+			GeneralStopRequested=1;
+		} else {
+			db_disconnect();
+ 			manage_restart_children();
+		}
+	}
+
  	manage_stop_children();
  	scoreboard_delete();
  
@@ -131,6 +137,8 @@
 
 void ParentSigHandler(int sig, siginfo_t * info, void *data)
 {
+	int saved_errno = errno;
+	
 	if (ParentPID != getpid()) {
 		trace(TRACE_INFO,
 		      "ParentSigHandler(): i'm no longer father");
@@ -162,6 +170,8 @@
 	default:
 		GeneralStopRequested = 1;
 	}
+
+	errno = saved_errno;
 }
 
 
