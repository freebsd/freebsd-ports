--- src/xine-utils/memcpy.c.orig	Thu Apr 22 22:57:12 2004
+++ src/xine-utils/memcpy.c	Thu Apr 22 22:57:55 2004
@@ -428,7 +428,8 @@
   /* FIXME: implement an equivalent for using optimized memcpy on other
             architectures */
 #ifndef _MSC_VER
-  return times(NULL);
+  struct tms xxx;
+  return times(&xxx);
 #else
 	return ((uint64_t)0);
 #endif /* _MSC_VER */
