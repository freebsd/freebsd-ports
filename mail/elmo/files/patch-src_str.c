--- src/str.c.orig	Sat Aug  7 11:07:36 2004
+++ src/str.c	Sat Aug  7 11:22:37 2004
@@ -217,7 +217,11 @@
   
         while (1){
                 max_size = str->size - str->len - 1;
+#if (defined(__FreeBSD__) && __FreeBSD__ < 5)
+		copy = ap;
+#else
                 va_copy (copy, ap);
+#endif
                 n = vsnprintf (str->str + str->len, max_size, fmt, copy);
                 if (n > -1 && n < max_size){
                         str->len += n;
