Index: server.c
===================================================================
--- server.c	(revision 1763)
+++ server.c	(revision 1787)
@@ -69,7 +69,7 @@
 
 	act.sa_sigaction = ParentSigHandler;
 	sigemptyset(&act.sa_mask);
-	act.sa_flags = SA_SIGINFO; 
+	act.sa_flags = SA_SIGINFO | SA_NOCLDSTOP;
 
 	sigaction(SIGCHLD, &act, 0);
 	sigaction(SIGINT, &act, 0);
@@ -152,6 +152,7 @@
 
 void ParentSigHandler(int sig, siginfo_t * info, void *data)
 {
+	pid_t chpid;
 	int saved_errno = errno;
 	
 	if (ParentPID != getpid()) {
@@ -175,7 +176,12 @@
 		break;
  
 	case SIGCHLD:
-		break;		/* ignore, wait for child in main loop */
+		/* ignore, wait for child in main loop */
+	        /* but we need to catch zombie */
+		if ((chpid = waitpid(-1,&sig,WNOHANG)) > 0)
+			scoreboard_release(chpid);
+		
+		break;		
 
 	case SIGHUP:
 		trace(TRACE_DEBUG,
