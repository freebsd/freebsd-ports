--- ./smbd/aio.c.orig	2010-01-14 10:12:10.000000000 +0000
+++ ./smbd/aio.c	2010-02-05 00:27:01.000000000 +0000
@@ -24,9 +24,6 @@
 
 /* The signal we'll use to signify aio done. */
 #ifndef RT_SIGNAL_AIO
-#ifndef SIGRTMIN
-#define SIGRTMIN	NSIG
-#endif
 #define RT_SIGNAL_AIO	(SIGRTMIN+3)
 #endif
 
