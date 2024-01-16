--- deps/openssl/openssl_no_asm.gypi.orig	2023-03-05 06:42:52 UTC
+++ deps/openssl/openssl_no_asm.gypi
@@ -44,7 +44,7 @@
       'includes': ['config/archs/linux64-riscv64/no-asm/openssl.gypi'],
     }, {
       # Other architectures don't use assembly
-      'includes': ['config/archs/linux-x86_64/no-asm/openssl.gypi'],
+      'includes': ['config/archs/linux-elf/no-asm/openssl.gypi'],
     }],
   ],
 }
