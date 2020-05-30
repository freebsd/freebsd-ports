--- include/types.h.orig	2020-05-30 22:59:57 UTC
+++ include/types.h
@@ -46,11 +46,7 @@ typedef uint32_t u32;
 
  */
 
-#ifdef __x86_64__
 typedef unsigned long long u64;
-#else
-typedef uint64_t u64;
-#endif                                                       /* ^__x86_64__ */
 
 typedef int8_t  s8;
 typedef int16_t s16;
