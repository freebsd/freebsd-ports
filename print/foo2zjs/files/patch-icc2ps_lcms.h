--- icc2ps/lcms.h	Sun Jun  4 14:21:49 2006
+++ icc2ps/lcms.h	Sun Jun  4 14:22:05 2006
@@ -133,9 +133,8 @@
 
 #if defined(__OpenBSD__) || defined(__NetBSD__) || defined(__FreeBSD__)
 #  include <sys/types.h>
-#  define USE_INT64           1
-#  define LCMSSLONGLONG       int_64_t
-#  define LCMSULONGLONG       u_int64_t
+#  define LCMSSLONGLONG       int64_t
+#  define LCMSULONGLONG       uint64_t
 #endif
 
 #ifdef USE_INT64
