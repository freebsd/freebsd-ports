--- deps/openssl/openssl_no_asm.gypi.orig	2018-05-11 12:27:27 UTC
+++ deps/openssl/openssl_no_asm.gypi
@@ -42,7 +42,7 @@
       'includes': ['config/archs/linux-x86_64/no-asm/openssl.gypi'],
     }, {
       # Other architectures don't use assembly
-      'includes': ['config/archs/linux-x86_64/no-asm/openssl.gypi'],
+      'includes': ['config/archs/linux-elf/no-asm/openssl.gypi'],
     }],
   ],
 }
