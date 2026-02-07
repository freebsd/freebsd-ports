--- libI77/fio.h.orig	1999-11-09 14:58:43 UTC
+++ libI77/fio.h
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
