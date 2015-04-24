--- src/node.cc.orig	2015-04-15 04:37:29 UTC
+++ src/node.cc
@@ -2790,7 +2790,7 @@ static void SignalExit(int signo) {
   struct sigaction sa;
   memset(&sa, 0, sizeof(sa));
   sa.sa_handler = SIG_DFL;
-  CHECK_EQ(sigaction(signo, &sa, nullptr), 0);
+  CHECK_EQ(sigaction(signo, &sa, NULL), 0);
 #endif
   raise(signo);
 }
