--- pan/sockets.c.orig	Thu Feb 27 13:15:49 2003
+++ pan/sockets.c	Thu Feb 27 13:24:02 2003
@@ -86,6 +86,9 @@
                 int              port)
 {
 	PanSocket * sock;
+#ifdef SIGPIPE
+	struct sigaction sv;
+#endif
 
 	/* sanity clause */
 	g_return_val_if_fail (is_nonempty_string (server_name), NULL);
@@ -94,7 +97,11 @@
 
 	/* needed on Unix */
 #	ifdef SIGPIPE
-	sigignore (SIGPIPE);
+	memset(&sv, 0, sizeof(sv));
+	sv.sa_handler = SIG_IGN;
+	sigemptyset(&sv.sa_mask);
+	sv.sa_flags = SA_RESTART;
+	sigaction(SIGPIPE, &sv, NULL);
 #	endif
 
 	/* create the socket */
