--- src/gsocket.c.orig	Tue May 27 14:11:08 2003
+++ src/gsocket.c	Tue May 27 14:11:58 2003
@@ -127,6 +127,11 @@
 #  define GSocket_Debug(args)
 #endif /* __GSOCKET_DEBUG__ */
 
+/* Added by Un-Thesis 2003-05-15 */
+/* Allows socket reuse */
+/* Code contributed by McCabe and arkanes */
+int intYes = 1;
+
 /* Global initialisers */
 
 int GSocket_Init(void)
@@ -400,7 +405,6 @@
 /* Added by Un-Thesis 2003-05-15 */
 /* Allows socket reuse */
 /* Code contributed by McCabe and arkanes */
-int intYes = 1;
 if(setsockopt(sck->m_fd, SOL_SOCKET, SO_REUSEADDR, &intYes, sizeof(int))) {
 	return GSOCK_IOERR;
 }
