--- include/CGAL/config.h.orig	2016-07-05 08:44:07 UTC
+++ include/CGAL/config.h
@@ -296,7 +296,8 @@
    || defined(__x86_64) || defined(__x86_64__) \
    || defined(__ia64) || defined(__ia64__) \
    || defined(_M_IX86) || defined(_M_IA64) \
-   || defined(_M_ALPHA) || defined(_WIN64)
+   || defined(_M_ALPHA) || defined(_WIN64) \
+   || defined(__arm)
 #  define CGAL_LITTLE_ENDIAN
 #else
 #  error Unknown endianness
