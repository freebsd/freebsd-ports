Index: lib/util.h
diff -u lib/util.h.orig lib/util.h
--- lib/util.h.orig	2015-04-23 13:51:33.000000000 +0900
+++ lib/util.h	2015-04-24 13:02:55.232366031 +0900
@@ -66,9 +66,7 @@
 # endif /* HAVE_PCREPOSIX_H */
 #endif /* ENABLE_REGEX */
 
-#ifndef __GNUC__
 typedef int (*__compar_fn_t)(const void *, const void *);
-#endif
 
 #define BIT32_MAX 4294967295U
 
