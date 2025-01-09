Fix the typo in the aarch64 macro

https://github.com/wolfSSL/wolfssl/pull/8346

--- wolfcrypt/src/cpuid.c.orig	2025-01-09 14:23:01 UTC
+++ wolfcrypt/src/cpuid.c
@@ -259,7 +259,7 @@
 
             if (features & CPUID_AARCH64_FEAT_AES)
                 cpuid_flags |= CPUID_AES;
-            if (features & CPUID_AARCH64_FEAT_PMULL)
+            if (features & CPUID_AARCH64_FEAT_AES_PMULL)
                 cpuid_flags |= CPUID_PMULL;
             if (features & CPUID_AARCH64_FEAT_SHA256)
                 cpuid_flags |= CPUID_SHA256;
