--- smbd/aio.c.orig	2009-02-24 07:38:16.000000000 +0000
+++ smbd/aio.c	2009-03-07 03:44:22.000000000 +0000
@@ -24,9 +24,6 @@
 
 /* The signal we'll use to signify aio done. */
 #ifndef RT_SIGNAL_AIO
-#ifndef SIGRTMIN
-#define SIGRTMIN	NSIG
-#endif
 #define RT_SIGNAL_AIO	(SIGRTMIN+3)
 #endif
 
