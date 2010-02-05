--- ./source3/smbd/aio.c.orig	2010-01-18 12:38:09.000000000 +0100
+++ ./source3/smbd/aio.c	2010-01-22 02:42:50.000000000 +0100
@@ -25,9 +25,6 @@
 
 /* The signal we'll use to signify aio done. */
 #ifndef RT_SIGNAL_AIO
-#ifndef SIGRTMIN
-#define SIGRTMIN	NSIG
-#endif
 #define RT_SIGNAL_AIO	(SIGRTMIN+3)
 #endif
 
