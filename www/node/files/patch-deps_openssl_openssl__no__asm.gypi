--- deps/openssl/openssl_no_asm.gypi.orig	2019-08-06 20:46:23 UTC
+++ deps/openssl/openssl_no_asm.gypi
@@ -46,7 +46,7 @@
       'includes': ['config/archs/linux64-mips64/no-asm/openssl.gypi'],
     }, {
       # Other architectures don't use assembly
-      'includes': ['config/archs/linux-x86_64/no-asm/openssl.gypi'],
+      'includes': ['config/archs/linux-elf/no-asm/openssl.gypi'],
     }],
   ],
 }
