--- include/signal.h.orig	2015-05-04 09:54:32 UTC
+++ include/signal.h
@@ -8,3 +8,7 @@
 #ifndef SIGINFO
 #define SIGINFO SIGUSR1
 #endif
+
+#ifndef _NSIG
+#define _NSIG NSIG
+#endif
