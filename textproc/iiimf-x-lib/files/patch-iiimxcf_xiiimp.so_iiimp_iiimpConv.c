--- iiimp/iiimpConv.c.orig	Tue Sep  7 20:42:04 2004
+++ iiimp/iiimpConv.c	Tue Sep  7 20:42:22 2004
@@ -44,7 +44,7 @@
 #if defined(sun)
 #define USE_ICONV
 #else
-#define USE_ICONV
+#define USE_CSCONV
 #endif
 #endif
 
