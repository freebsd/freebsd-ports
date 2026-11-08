--- ccan/ccan/asort/asort.h.orig	2026-10-08 08:33:17 UTC
+++ ccan/ccan/asort/asort.h
@@ -27,8 +27,12 @@ _asort((base), (num), sizeof(*(base)),					\
  * first libc include — we can't control our includers, so declare it
  * ourselves (the configurator only sets this where this GNU signature
  * was detected). */
+#ifndef qsort_r
+/* On some systems (e.g. FreeBSD) qsort_r() is a macro that is already
+ * defined here by stdlib.h. The below would brick the compilation. */
 void qsort_r(void *base, size_t nmemb, size_t size,
 	     int (*compar)(const void *, const void *, void *), void *arg);
+#endif /* qsort_r */
 #define _asort(b, n, s, cmp, ctx) qsort_r(b, n, s, cmp, ctx)
 #else
 void _asort(void *base, size_t nmemb, size_t size,
