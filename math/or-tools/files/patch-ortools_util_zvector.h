--- ortools/util/zvector.h.orig	2020-07-20 23:36:37 UTC
+++ ortools/util/zvector.h
@@ -17,7 +17,11 @@
 #if defined(__APPLE__) && defined(__GNUC__)
 #include <machine/endian.h>
 #elif !defined(_MSC_VER)
+#if defined(__FreeBSD__)
+#include <sys/endian.h>
+#else
 #include <endian.h>
+#endif
 #endif
 #include <climits>
 #include <cstdio>
