--- krep.c.orig	2026-05-19 07:06:16 UTC
+++ krep.c
@@ -4925,6 +4925,27 @@ uint64_t memchr_short_search(const search_params_t *pa
 // Handles case-sensitive patterns of any length.
 // Uses 2x 16-byte loads per iteration with fast mask extraction via
 // vshrn/vmovn instead of store-to-memory.
+
+#ifdef __aarch64__
+static inline bool
+is_nonzero(uint8x16_t a)
+{
+	return (vmaxvq_u8(a) != 0);
+}
+#else
+/* no vmaxvq_u8() on AArch32 */
+static inline bool
+is_nonzero(uint8x16_t a)
+{
+	uint8x8_t a8, a4;
+
+	a8 = vmax_u8(vget_low_u8(a), vget_high_u8(a));
+	a4 = vpmax_u8(a8, a8);
+
+	return (vget_lane_u32(a4, 0) != 0);
+}
+#endif /* defined(__aarch64__) */
+
 uint64_t neon_search(const search_params_t *params,
                      const char *text_start,
                      size_t text_len,
