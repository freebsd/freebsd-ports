--- ts.c.orig	Tue Apr 13 20:23:45 2004
+++ ts.c	Tue Apr 13 20:24:18 2004
@@ -206,7 +206,11 @@
 
     if (format == NULL)
         return NULL;
+#ifdef __amd64__
+    va_copy(ap2,ap);
+#else
     ap2 = ap;
+#endif
     if ((n = ts_suite_mvxprintf(NULL, 0, format, ap)) == -1)
         return NULL;
     if ((buffer = (char *)malloc(n+1)) == NULL)
