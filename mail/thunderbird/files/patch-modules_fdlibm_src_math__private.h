commit 7a20fbf537ee0867244109d1ea48a8ad9de2e4ea
Author: Christoph Moench-Tegeder <cmt@burggraben.net>

    align typedefs with our libm for historical CPUs

diff --git modules/fdlibm/src/math_private.h modules/fdlibm/src/math_private.h
index f4373f27834a..3b898241660f 100644
--- modules/fdlibm/src/math_private.h
+++ modules/fdlibm/src/math_private.h
@@ -30,9 +30,17 @@
  * Adapted from https://github.com/freebsd/freebsd-src/search?q=__double_t
  */
 
+#ifdef __LP64__
 typedef double      __double_t;
+#else
+typedef long double __double_t;
+#endif
 typedef __double_t  double_t;
+#ifdef __LP64__
 typedef float       __float_t;
+#else
+typedef long double __float_t;
+#endif
 
 /*
  * The original fdlibm code used statements like:
