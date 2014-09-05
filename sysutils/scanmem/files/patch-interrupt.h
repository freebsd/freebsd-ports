--- interrupt.h.orig	2009-12-14 15:15:26 UTC
+++ interrupt.h
@@ -10,7 +10,7 @@
 /* small header file to manage interrupted commands */
 
 static sigjmp_buf jmpbuf;       /* used when aborting a command due to interrupt */
-static sighandler_t oldsig;     /* reinstalled before longjmp */
+static sig_t oldsig;     /* reinstalled before longjmp */
 static unsigned intused;
 
 /* signal handler to handle interrupt during a commands */
