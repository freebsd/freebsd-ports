--- appl/gssftp/ftp/ftp_var.h.orig	Mon Jun 16 15:37:40 2003
+++ appl/gssftp/ftp/ftp_var.h	Tue Jul 29 22:14:57 2003
@@ -33,6 +33,10 @@
  *	@(#)ftp_var.h	5.9 (Berkeley) 6/1/90
  */
 
+#if defined(__FreeBSD_cc_version) && __FreeBSD_cc_version > 500000
+#undef __BSD_VISIBLE
+#endif
+
 #ifdef _WIN32
 #include <windows.h>
 #include <winsock2.h>
