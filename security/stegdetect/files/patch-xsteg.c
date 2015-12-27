--- xsteg.c.orig	2004-08-31 14:58:21 UTC
+++ xsteg.c
@@ -56,9 +56,6 @@
 #define FLAG_DOINVIS	0x0008
 #define FLAG_DOF5	0x0010
 
-extern int (*event_sigcb)(void);
-extern int event_gotsig;
-
 struct event start_ev;
 struct event gtk_ev;
 int quit = 0;
@@ -744,8 +741,7 @@ chld_handler(int sig)
 	sigprocmask(SIG_BLOCK, &set, &oldset);
 
 	while ((pid = waitpid(-1, &status, WNOHANG)) > 0) {
-		if (WIFEXITED(status) || WIFSIGNALED(status))
-			event_gotsig = 1;
+		;
 	}
 
 	signal(SIGCHLD, chld_handler);
@@ -1106,8 +1102,7 @@ main(int argc, char *argv[] )
 	gtk_widget_show(window);
 
 	event_init();
-	event_sigcb = signal_cb;
-
+	
 	add_gtk_timeout();
 
 	event_dispatch();
