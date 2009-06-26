--- ./smbd/aio.c.orig	2009-06-23 09:35:13.000000000 +0000
+++ ./smbd/aio.c	2009-06-26 00:41:37.000000000 +0000
@@ -24,9 +24,6 @@
 
 /* The signal we'll use to signify aio done. */
 #ifndef RT_SIGNAL_AIO
-#ifndef SIGRTMIN
-#define SIGRTMIN	NSIG
-#endif
 #define RT_SIGNAL_AIO	(SIGRTMIN+3)
 #endif
 
