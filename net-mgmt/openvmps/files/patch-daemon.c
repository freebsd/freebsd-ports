--- daemon.c.orig	Tue Jan 25 18:00:12 2005
+++ daemon.c	Tue Jan 25 18:00:47 2005
@@ -44,7 +44,10 @@
 
 {
 	register int	childpid;
-
+#ifdef	VMPS_CHECK_BSD
+	int fd;
+#endif
+	
 #ifdef	SIGTTOU
 	signal(SIGTTOU, SIG_IGN);
 #endif
