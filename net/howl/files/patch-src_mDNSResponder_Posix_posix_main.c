--- src/mDNSResponder/Posix/posix_main.c.orig	Fri Jul  2 00:49:18 2004
+++ src/mDNSResponder/Posix/posix_main.c	Fri Jul  2 00:49:32 2004
@@ -239,6 +239,7 @@
 	signal(SIGHUP, sw_mdnsd_signal_handler);
 	signal(SIGUSR1, sw_mdnsd_signal_handler);
 	signal(SIGUSR2, sw_mdnsd_signal_handler);
+	signal(SIGPIPE, SIG_IGN);
 
 	sigfillset(&signalSet);
 
