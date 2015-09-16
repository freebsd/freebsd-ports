--- finch/libgnt/gntmain.c.orig	2015-07-10 05:07:01.325805007 -0400
+++ finch/libgnt/gntmain.c	2015-07-10 13:05:46.746810688 -0400
@@ -407,10 +407,11 @@ raise:
 
 #ifdef SIGWINCH
 static void (*org_winch_handler)(int);
+static void (*org_winch_handler_sa)(int, siginfo_t *, void *);
 #endif
 
 static void
-sighandler(int sig)
+sighandler(int sig, siginfo_t *info, void *data)
 {
 	switch (sig) {
 #ifdef SIGWINCH
@@ -419,16 +420,15 @@ sighandler(int sig)
 		g_idle_add((GSourceFunc)refresh_screen, NULL);
 		if (org_winch_handler)
 			org_winch_handler(sig);
-		signal(SIGWINCH, sighandler);
+		if (org_winch_handler_sa)
+			org_winch_handler_sa(sig, info, data);
 		break;
 #endif
 	case SIGCHLD:
 		clean_pid();
-		signal(SIGCHLD, sighandler);
 		break;
 	case SIGINT:
 		ask_before_exit();
-		signal(SIGINT, sighandler);
 		break;
 	}
 }
@@ -456,6 +456,10 @@ void gnt_init()
 {
 	char *filename;
 	const char *locale;
+	struct sigaction act;
+#ifdef SIGWINCH
+	struct sigaction oact;
+#endif
 
 	if (channel)
 		return;
@@ -501,11 +505,25 @@ void gnt_init()
 	werase(stdscr);
 	wrefresh(stdscr);
 
+	act.sa_sigaction = sighandler;
+	sigemptyset(&act.sa_mask);
+	act.sa_flags = SA_SIGINFO;
+
 #ifdef SIGWINCH
-	org_winch_handler = signal(SIGWINCH, sighandler);
+	org_winch_handler = NULL;
+	org_winch_handler_sa = NULL;
+	sigaction(SIGWINCH, &act, &oact);
+	if (oact.sa_flags & SA_SIGINFO)
+	{
+		org_winch_handler_sa = oact.sa_sigaction;
+	}
+	else if (oact.sa_handler != SIG_DFL && oact.sa_handler != SIG_IGN)
+	{
+		org_winch_handler = oact.sa_handler;
+	}
 #endif
-	signal(SIGCHLD, sighandler);
-	signal(SIGINT, sighandler);
+	sigaction(SIGCHLD, &act, NULL);
+	sigaction(SIGINT, &act, NULL);
 	signal(SIGPIPE, SIG_IGN);
 
 #if !GLIB_CHECK_VERSION(2, 36, 0)
