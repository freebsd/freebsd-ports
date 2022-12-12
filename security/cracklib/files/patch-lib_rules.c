--- lib/rules.c.orig	2019-02-14 01:54:41 UTC
+++ lib/rules.c
@@ -26,6 +26,8 @@ Debug(val, a, b, c, d, e, f, g)
 {
     fprintf(stderr, a, b, c, d, e, f, g);
 }
+#elif 1
+#define Debug(n, f, ...) do {} while (0)
 #else
 static void
 Debug(val, a, b, c, d, e, f, g)
