--- appl/gssftp/ftp/ftp_var.h.orig	Tue Jun 17 02:37:40 2003
+++ appl/gssftp/ftp/ftp_var.h	Sat Aug 30 05:30:44 2003
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
@@ -57,9 +61,7 @@
 typedef void (*sig_t)(int);
 typedef void sigtype;
 #else
-#define sig_t my_sig_t
 #define sigtype krb5_sigtype
-typedef sigtype (*sig_t)();
 #endif
 
 /*
