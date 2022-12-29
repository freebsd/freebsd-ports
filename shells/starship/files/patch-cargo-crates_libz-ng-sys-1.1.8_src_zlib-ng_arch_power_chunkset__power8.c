--- cargo-crates/libz-ng-sys-1.1.8/src/zlib-ng/arch/power/chunkset_power8.c.orig	2022-12-29 16:08:43 UTC
+++ cargo-crates/libz-ng-sys-1.1.8/src/zlib-ng/arch/power/chunkset_power8.c
@@ -27,7 +27,7 @@ static inline void chunkmemset_4(uint8_t *from, chunk_
 }
 
 static inline void chunkmemset_8(uint8_t *from, chunk_t *chunk) {
-    uint64_t tmp;
+    unsigned long long tmp;
     zmemcpy_8(&tmp, from);
     *chunk = (vector unsigned char)vec_splats(tmp);
 }
