--- libI77/fio.h.orig	Tue Nov  9 15:58:43 1999
+++ libI77/fio.h	Tue Dec 16 23:53:43 2003
@@ -17,6 +17,12 @@
 #endif
 #endif
 
+#ifdef  __FreeBSD__
+#ifndef NON_UNIX_STDIO
+#define NON_UNIX_STDIO
+#endif
+#endif
+
 #ifdef UIOLEN_int
 typedef int uiolen;
 #else
