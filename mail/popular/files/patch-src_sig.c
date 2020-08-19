--- src/sig.c.orig	2002-09-15 12:27:16 UTC
+++ src/sig.c
@@ -114,7 +114,6 @@ signal_init(int c)
   signal_set(sigHandler, SIGQUIT, 0);
   signal_set(sigHandler, SIGUSR1, 0);
   signal_set(sigHandler, SIGUSR2, 0);
-  signal_set(sigHandler, SIGPWR,  0);
 }
 
 
@@ -138,7 +137,6 @@ signal_init_child()
   signal_set(sigDefault, SIGQUIT, 0);
   signal_set(sigDefault, SIGUSR1, 0);
   signal_set(sigDefault, SIGUSR2, 0);
-  signal_set(sigDefault, SIGPWR,  0);
 
   if (signal_remember[SIGTERM] || signal_remember[SIGINT]) {
     /* XLOG-DOC:INF:0133:got_term_signal
