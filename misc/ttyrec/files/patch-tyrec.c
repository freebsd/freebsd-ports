--- ttyrec.c.orig	Tue Jun  4 21:52:00 2002
+++ ttyrec.c	Tue Jun  4 21:52:12 2002
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
 
