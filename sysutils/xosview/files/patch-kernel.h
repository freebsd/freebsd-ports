--- bsd/kernel.h.orig	Fri May 29 14:21:36 1998
+++ bsd/kernel.h	Sat Jun 10 14:18:22 2000
@@ -67,7 +67,11 @@
 #endif
 
 
-#define NUM_INTR	16
+#if defined(XOSVIEW_FREEBSD) && defined(__alpha__)
+# define NUM_INTR	256
+#else
+# define NUM_INTR	16
+#endif
 
 int
 BSDIntrInit();
