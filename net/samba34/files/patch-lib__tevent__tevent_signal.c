--- ./lib/tevent/tevent_signal.c.orig	2010-01-22 02:45:28.000000000 +0100
+++ ./lib/tevent/tevent_signal.c	2010-01-22 02:45:54.000000000 +0100
@@ -30,7 +30,7 @@
 #include "tevent_internal.h"
 #include "tevent_util.h"
 
-#define NUM_SIGNALS 64
+#define NUM_SIGNALS SIGRTMAX
 
 /* maximum number of SA_SIGINFO signals to hold in the queue.
   NB. This *MUST* be a power of 2, in order for the ring buffer
