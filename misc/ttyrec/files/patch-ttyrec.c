--- ttyrec.c.orig	2002-06-04 21:52:00 UTC
+++ ttyrec.c
@@ -202,11 +202,7 @@
 void
 finish()
 {
-#if defined(SVR4)
 	int status;
-#else /* !SVR4 */
-	union wait status;
-#endif /* !SVR4 */
 	register int pid;
 	register int die = 0;
 
