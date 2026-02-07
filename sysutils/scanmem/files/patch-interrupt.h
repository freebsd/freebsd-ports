--- interrupt.h.orig	2017-10-13 21:53:16 UTC
+++ interrupt.h
@@ -30,7 +30,7 @@
 /* small header file to manage interrupted commands */
 
 static sigjmp_buf jmpbuf;       /* used when aborting a command due to an interrupt */
-static sighandler_t oldsig;     /* reinstalled before longjmp */
+static sig_t oldsig;     /* reinstalled before longjmp */
 static unsigned intused;
 
 /* signal handler used to handle an interrupt during commands */
