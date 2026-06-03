--- test/taylor_atan.cpp.orig
+++ test/taylor_atan.cpp
@@ -48,7 +48,16 @@
                                  >{};
 
-constexpr bool skip_batch_ld = false;
+// On x86/x86-64, long double is 80-bit extended precision. Batch Taylor
+// integration uses double-length (DL) arithmetic via EFT internally, which
+// relies on fmal() being an exact fused multiply-add. Since there is no
+// hardware FMA instruction for 80-bit extended precision on x86, the system
+// fmal() is not exact, making batch results unreliable for long double.
+#if defined(HEYOKA_ARCH_X86)
+constexpr bool skip_batch_ld = true;
+#else
+constexpr bool skip_batch_ld = false;
+#endif
 
 TEST_CASE("taylor atan decompose bug 00")
