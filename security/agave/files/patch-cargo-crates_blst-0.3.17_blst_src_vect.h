--- cargo-crates/blst-0.3.17/blst/src/vect.h.orig	2026-11-13 21:00:41 UTC
+++ cargo-crates/blst-0.3.17/blst/src/vect.h	2026-11-13 21:00:41 UTC
@@ -18,7 +18,7 @@
 typedef unsigned __int64 limb_t;
 # define LIMB_T_BITS    64
 
-#elif defined(__BLST_NO_ASM__) || defined(__wasm64__)
+#elif defined(__wasm64__)
 typedef unsigned int limb_t;
 # define LIMB_T_BITS    32
 # ifndef __BLST_NO_ASM__
@@ -31,8 +31,10 @@
 #   define LIMB_T_BITS   64
 #  else
 #   define LIMB_T_BITS   32
-#   define __BLST_NO_ASM__
 #  endif
+# ifndef __BLST_NO_ASM__
+#  define __BLST_NO_ASM__
+# endif
 #endif
 
 /*
