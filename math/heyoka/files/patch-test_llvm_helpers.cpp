--- test/llvm_helpers.cpp.orig
+++ test/llvm_helpers.cpp
@@ -1498,11 +1498,19 @@
 #if defined(HEYOKA_HAVE_REAL128)
                 if constexpr (!std::is_same_v<fp_t, mppp::real128>) {
 #endif
-
+// On x86/x86-64, long double is 80-bit extended precision and there is no
+// hardware FMA instruction for this type. The system fmal() is not an exact
+// FMA, so the EFT property cannot be guaranteed for long double.
+#if defined(HEYOKA_ARCH_X86)
+                if constexpr (!std::is_same_v<fp_t, long double>) {
+#endif
                     using mp_fp_t = mppp::real;
                     const auto prec = std::numeric_limits<fp_t>::digits * 2;
 
                     REQUIRE(mp_fp_t(x, prec) + mp_fp_t(y, prec) == mp_fp_t(a, prec) * mp_fp_t(b, prec));
+#if defined(HEYOKA_ARCH_X86)
+                }
+#endif
 #if defined(HEYOKA_HAVE_REAL128)
                 }
 #endif
@@ -1588,10 +1596,19 @@
 #if defined(HEYOKA_HAVE_REAL128)
                         if constexpr (!std::is_same_v<fp_t, mppp::real128>) {
 #endif
+// On x86/x86-64, long double is 80-bit extended precision and there is no
+// hardware FMA instruction for this type. The system fmal() is not an exact
+// FMA, so the EFT property cannot be guaranteed for long double.
+#if defined(HEYOKA_ARCH_X86)
+                        if constexpr (!std::is_same_v<fp_t, long double>) {
+#endif
                             using mp_fp_t = mppp::real;
                             const auto prec = std::numeric_limits<fp_t>::digits * 2;
 
                             REQUIRE(mp_fp_t(xv, prec) + mp_fp_t(yv, prec) == mp_fp_t(a, prec) * mp_fp_t(b, prec));
+#if defined(HEYOKA_ARCH_X86)
+                        }
+#endif
 #if defined(HEYOKA_HAVE_REAL128)
                         }
 #endif
