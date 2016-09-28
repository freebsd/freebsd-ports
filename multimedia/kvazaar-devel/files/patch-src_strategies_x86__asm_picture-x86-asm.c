./.libs/libkvazaar.so: undefined reference to `kvz_reg_sad_sse41'

--- src/strategies/x86_asm/picture-x86-asm.c.orig	2016-09-27 17:49:45 UTC
+++ src/strategies/x86_asm/picture-x86-asm.c
@@ -81,13 +81,17 @@ static unsigned reg_sad_x86_asm(const kv
     }
   }
 
+#if COMPILE_INTEL_SSE41
   if (width * height >= 16) {
     // Call the vectorized general SAD SSE41 function when the block
     // is big enough to make it worth it.
     return kvz_reg_sad_sse41(data1, data2, width, height, stride1, stride2);
   } else {
+#endif
     return kvz_sad_other_avx(data1, data2, width, height, stride1);
+#if COMPILE_INTEL_SSE41
   }
+#endif
 }
 
 #endif //defined(KVZ_COMPILE_ASM)
