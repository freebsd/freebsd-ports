--- src/gxfixed.h.orig	2013-04-30 11:29:39.000000000 +0900
+++ src/gxfixed.h	2013-04-30 11:31:03.000000000 +0900
@@ -27,12 +27,22 @@
  * quantities: integers lose accuracy in crucial places,
  * and floating point arithmetic is slow.
  */
-typedef long fixed;
-typedef ulong ufixed;		/* only used in a very few places */
-#define ARCH_SIZEOF_FIXED ARCH_SIZEOF_LONG
+#if ARCH_SIZEOF_INT == 4
+typedef int fixed;
+typedef uint ufixed;		/* only used in a very few places */
+# define ARCH_SIZEOF_FIXED ARCH_SIZEOF_INT
+# define max_fixed max_int
+# define min_fixed min_int
+#else
+# if ARCH_SIZEOF_LONG == 4
+ typedef long fixed;
+ typedef ulong ufixed;		/* only used in a very few places */
+#  define ARCH_SIZEOF_FIXED ARCH_SIZEOF_LONG
+#  define max_fixed max_long
+#  define min_fixed min_long
+# endif
+#endif
 
-#define max_fixed max_long
-#define min_fixed min_long
 #define fixed_0 0L
 #define fixed_epsilon 1L
 /*
@@ -120,13 +130,8 @@
 #define fixed_truncated(x) ((x) < 0 ? fixed_ceiling(x) : fixed_floor(x))
 
 /* Define the largest and smallest integer values that fit in a fixed. */
-#if arch_sizeof_int == arch_sizeof_long
-#  define max_int_in_fixed fixed2int(max_fixed)
-#  define min_int_in_fixed fixed2int(min_fixed)
-#else
-#  define max_int_in_fixed max_int
-#  define min_int_in_fixed min_int
-#endif
+#define max_int_in_fixed fixed2int(max_fixed)
+#define min_int_in_fixed fixed2int(min_fixed)
 
 #ifdef USE_FPU
 #  define USE_FPU_FIXED (USE_FPU < 0 && arch_floats_are_IEEE && arch_sizeof_long == 4)
