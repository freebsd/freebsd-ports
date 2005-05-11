--- filter/filter_modfps.c.orig	Sun May  8 16:55:54 2005
+++ filter/filter_modfps.c	Sun May  8 16:57:01 2005
@@ -62,7 +62,14 @@
 //#define DEBUG 1
 
 // FIXME
+#if !defined(HAV_LRINTF)
+static inline long int lrint(double x)
+{
+	return (long)(rint(x));
+}
+#else
 extern long int lrint(double x);
+#endif
 
 static int show_results=0;
 
