--- src/daemonize.c.orig	2015-01-10 21:06:25.000000000 -0500
+++ src/daemonize.c	2015-01-10 21:08:15.000000000 -0500
@@ -39,6 +39,7 @@
 	/* ignore HUP we will receive when session leader (first child) terminates */
 	sigemptyset(&sa.sa_mask);
 	sa.sa_handler = SIG_IGN;
+	sa.sa_flags = 0;
 	if (sigaction(SIGHUP, &sa, NULL) < 0) {
 		report(LOG_ERR, "sigaction: %s", get_errmsg());
 		report(LOG_NOTICE, "exiting");
