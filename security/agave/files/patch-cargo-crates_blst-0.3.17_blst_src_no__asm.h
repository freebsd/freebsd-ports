--- cargo-crates/blst-0.3.17/blst/src/no_asm.h.orig	2026-11-13 21:00:41 UTC
+++ cargo-crates/blst-0.3.17/blst/src/no_asm.h	2026-11-13 21:00:41 UTC
@@ -6,6 +6,8 @@
 
 #if LIMB_T_BITS==32
 typedef unsigned long long llimb_t;
+#else
+typedef unsigned __int128 llimb_t;
 #endif
 
 #if !defined(__STDC_VERSION__) || __STDC_VERSION__<199901 || defined(__STDC_NO_VLA__)
@@ -1103,7 +1105,7 @@
 static limb_t quot_rem_n(limb_t *div_rem, const limb_t *divisor,
                                           limb_t quotient, size_t n)
 {
-    __builtin_assume(n != 0 && n%2 == 0);
+    __builtin_assume(n != 0);
     llimb_t limbx;
     limb_t tmp[n+1], carry, mask, borrow;
     size_t i;
