--- filter/filter_modfps.c.old	Sat Aug 21 13:11:20 2004
+++ filter/filter_modfps.c	Sat Aug 21 13:13:33 2004
@@ -77,6 +77,13 @@
 #include "framebuffer.h"
 #include "optstr.h"
 
+#if !defined(HAVE_LRINTF)
+static inline long int lrint(double x)
+{
+    return (long)(rint(x));
+}
+#endif
+
 static int show_results=0;
 
 /*-------------------------------------------------
