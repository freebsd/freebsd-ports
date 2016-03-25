--- src/gcc.h.orig	2016-03-24 18:58:27 UTC
+++ src/gcc.h
@@ -310,7 +310,7 @@
  * warning purposedly for some section of the file and then later restore
  * the original warnings.
  */
-#if HAS_GCC(3, 0)
+#if HAS_GCC(4, 8)
 #define G_IGNORE_PUSH(x) \
 	G_PRAGMA(GCC diagnostic push) \
 	G_PRAGMA(GCC diagnostic ignored #x)
