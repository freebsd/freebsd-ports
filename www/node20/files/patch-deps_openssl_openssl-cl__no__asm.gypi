--- deps/openssl/openssl-cl_no_asm.gypi.orig	2023-05-16 06:58:19 UTC
+++ deps/openssl/openssl-cl_no_asm.gypi
@@ -1,4 +1,5 @@
 {
+  'defines': ['OPENSSL_NO_ASM'],
   'conditions': [
     ['target_arch=="ppc64" and OS=="aix"', {
       'includes': ['config/archs/aix64-gcc-as/no-asm/openssl-cl.gypi'],
@@ -43,7 +44,7 @@
       'includes': ['config/archs/linux64-riscv64/no-asm/openssl-cl.gypi'],
     }, {
       # Other architectures don't use assembly
-      'includes': ['config/archs/linux-x86_64/no-asm/openssl-cl.gypi'],
+      'includes': ['config/archs/linux-elf/no-asm/openssl-cl.gypi'],
     }],
   ],
 }
