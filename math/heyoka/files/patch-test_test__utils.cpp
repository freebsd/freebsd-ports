--- test/test_utils.cpp.orig
+++ test/test_utils.cpp
@@ -186,7 +186,17 @@
             const auto jet_scalar = tc_to_jet(ta);
 
             for (auto i = 0ul; i < dim * 4ul; ++i) {
+// On x86/x86-64, long double is 80-bit extended precision. Batch Taylor
+// integration uses double-length arithmetic via EFT internally. Since the
+// system fmal() is not an exact FMA for 80-bit long double, the batch
+// results may differ from the scalar results. Skip this comparison.
+#if defined(HEYOKA_ARCH_X86)
+                if constexpr (!std::is_same_v<T, long double>) {
+#endif
                 REQUIRE(jet_scalar[i] == approximately(jet_batch[i * batch_size + batch_idx], tol));
+#if defined(HEYOKA_ARCH_X86)
+                }
+#endif
             }
         }
     }
