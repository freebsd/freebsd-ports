--- deps/openssl/openssl_no_asm.gypi.orig	2023-03-28 21:14:18 UTC
+++ deps/openssl/openssl_no_asm.gypi
@@ -50,7 +50,7 @@
       'includes': ['config/archs/linux64-riscv64/no-asm/openssl.gypi'],
     }, {
       # Other architectures don't use assembly
-      'includes': ['config/archs/linux-x86_64/no-asm/openssl.gypi'],
+      'includes': ['config/archs/linux-elf/no-asm/openssl.gypi'],
     }],
   ],
 }
