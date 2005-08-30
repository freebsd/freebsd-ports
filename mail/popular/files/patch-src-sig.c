--- src/sig.c.orig	Sun Sep 15 14:27:16 2002
+++ src/sig.c	Mon Jul 11 16:21:23 2005
@@ -114,7 +114,6 @@
   signal_set(sigHandler, SIGQUIT, 0);
   signal_set(sigHandler, SIGUSR1, 0);
   signal_set(sigHandler, SIGUSR2, 0);
-  signal_set(sigHandler, SIGPWR,  0);
 }
 
 
@@ -138,7 +137,6 @@
   signal_set(sigDefault, SIGQUIT, 0);
   signal_set(sigDefault, SIGUSR1, 0);
   signal_set(sigDefault, SIGUSR2, 0);
-  signal_set(sigDefault, SIGPWR,  0);
 
   if (signal_remember[SIGTERM] || signal_remember[SIGINT]) {
     /* XLOG-DOC:INF:0133:got_term_signal
