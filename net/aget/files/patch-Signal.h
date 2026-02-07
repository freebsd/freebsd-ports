--- Signal.h.orig	2020-09-22 19:16:50 UTC
+++ Signal.h
@@ -4,7 +4,7 @@
 #include <signal.h>
 #include <pthread.h>
 
-sigset_t signal_set;
+extern sigset_t signal_set;
 
 void * signal_waiter(void *arg);
 void sigint_handler(void);
