--- lib/ts/Compatability.h.orig	2014-10-08 13:41:39.000000000 -0400
+++ lib/ts/Compatability.h	2014-10-08 13:42:29.000000000 -0400
@@ -55,7 +55,7 @@
 #if defined(linux)
 #define NEED_ALTZONE_DEFINED
 #define MAP_SHARED_MAP_NORESERVE (MAP_SHARED)
-#elif defined(darwin)
+#elif defined(darwin) || defined(__FreeBSD__)
 #define MAP_SHARED_MAP_NORESERVE (MAP_SHARED)
 #elif defined(solaris)
 #define NEED_ALTZONE_DEFINED
