--- include/memory.h	2014-04-01 07:44:11.659215390 +0000
+++ include/memory.h	2014-04-01 07:42:15.054225075 +0000
@@ -49,7 +49,7 @@
 /* forte (and maybe others) don't like double declarations, 
  * so we don't declare the inlines unless GNUC
  */
-#ifdef __GNUC__
+#if defined(__GNUC__) && !defined(__clang__)
 extern inline void *
 MyMalloc(size_t size)
 {
