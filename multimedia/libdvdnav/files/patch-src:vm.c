--- src/vm.c.orig	Fri Feb 20 00:49:57 2004
+++ src/vm.c	Fri Feb 20 00:54:31 2004
@@ -47,6 +47,10 @@
 #define lseek64 lseek
 #endif /* _MSC_VER */
 
+#ifdef __FreeBSD__
+#define lseek64 lseek
+#endif
+
 /*
 #define STRICT
 */
