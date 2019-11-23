--- src/3rdparty/chromium/base/third_party/dmg_fp/dtoa.cc.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/base/third_party/dmg_fp/dtoa.cc
@@ -186,7 +186,11 @@
  *	used for input more than STRTOD_DIGLIM digits long (default 40).
  */
 
+#ifdef __BIG_ENDIAN__
+#define IEEE_MC68k
+#else
 #define IEEE_8087
+#endif
 #define NO_HEX_FP
 
 #ifndef Long
