--- third_party/xsimd/include/xsimd/types/xsimd_vsx_register.hpp.orig	2026-06-28 10:55:46.683534000 +0200
+++ third_party/xsimd/include/xsimd/types/xsimd_vsx_register.hpp	2026-06-28 10:55:46.694422000 +0200
@@ -64,10 +64,10 @@
         XSIMD_DECLARE_SIMD_BOOL_VSX_REGISTER(short, short);
         XSIMD_DECLARE_SIMD_BOOL_VSX_REGISTER(unsigned int, int);
         XSIMD_DECLARE_SIMD_BOOL_VSX_REGISTER(int, int);
-        XSIMD_DECLARE_SIMD_BOOL_VSX_REGISTER(unsigned long, long);
-        XSIMD_DECLARE_SIMD_BOOL_VSX_REGISTER(long, long);
+        XSIMD_DECLARE_SIMD_BOOL_VSX_REGISTER(unsigned long, long long);
+        XSIMD_DECLARE_SIMD_BOOL_VSX_REGISTER(long, long long);
         XSIMD_DECLARE_SIMD_BOOL_VSX_REGISTER(float, int);
-        XSIMD_DECLARE_SIMD_BOOL_VSX_REGISTER(double, long);
+        XSIMD_DECLARE_SIMD_BOOL_VSX_REGISTER(double, long long);
 
 #undef XSIMD_DECLARE_SIMD_BOOL_VSX_REGISTER
     }
