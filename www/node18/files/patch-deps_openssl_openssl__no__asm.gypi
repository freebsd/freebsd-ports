--- deps/openssl/openssl_no_asm.gypi.orig	2020-09-08 12:17:11 UTC
+++ deps/openssl/openssl_no_asm.gypi
@@ -48,7 +48,7 @@
       'includes': ['config/archs/linux64-mips64/no-asm/openssl.gypi'],
     }, {
       # Other architectures don't use assembly
-      'includes': ['config/archs/linux-x86_64/no-asm/openssl.gypi'],
+      'includes': ['config/archs/linux-elf/no-asm/openssl.gypi'],
     }],
   ],
 }
