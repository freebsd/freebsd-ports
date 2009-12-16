--- libclamav/spin.c
+++ libclamav/spin.c
@@ -146,7 +146,7 @@ static uint32_t summit (char *src, int size)
       eax ^= ebx>>8 & 0xff;
       eax += 0x7801a108;
       eax ^= ebx;
-      CLI_ROR(eax, ebx&0xff);
+      CLI_ROR(eax, ebx&0x1f);
       swap = eax;
       eax = ebx;
       ebx = swap;

