--- utils/s2n_random.c.orig	2018-08-07 15:09:08 UTC
+++ utils/s2n_random.c
@@ -324,8 +324,13 @@ int s2n_get_rdrand_data(struct s2n_blob *out)
     int space_remaining = 0;
     struct s2n_stuffer stuffer = {{0}};
     union {
-        uint64_t u64;
+#if defined(__x86_64__)
+        uint64_t value;
         uint8_t u8[8];
+#else
+        uint32_t value;
+        uint8_t u8[4];
+#endif
     } output;
 
     GUARD(s2n_stuffer_init(&stuffer, out));
@@ -334,7 +339,7 @@ int s2n_get_rdrand_data(struct s2n_blob *out)
         int success = 0;
 
         for (int tries = 0; tries < 10; tries++) {
-            __asm__ __volatile__(".byte 0x48;\n" ".byte 0x0f;\n" ".byte 0xc7;\n" ".byte 0xf0;\n" "adcl $0x00, %%ebx;\n":"=b"(success), "=a"(output.u64)
+            __asm__ __volatile__(".byte 0x48;\n" ".byte 0x0f;\n" ".byte 0xc7;\n" ".byte 0xf0;\n" "adcl $0x00, %%ebx;\n":"=b"(success), "=a"(output.value)
                                  :"b"(0)
                                  :"cc");
 
