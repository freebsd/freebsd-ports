--- deps/openssl/openssl_no_asm.gypi.orig	2018-04-24 14:41:22 UTC
+++ deps/openssl/openssl_no_asm.gypi
@@ -1,7 +1,10 @@
 {
   'defines': ['OPENSSL_NO_ASM'],
   'conditions': [
-    ['target_arch=="ppc" and OS=="aix"', {
+    ['OS=="freebsd"', {
+      # noasm BSD-x86_64 for all FreeBSD archs
+      'includes': ['config/archs/BSD-x86_64/no-asm/openssl.gypi'],
+    }, 'target_arch=="ppc" and OS=="aix"', {
       'includes': ['config/archs/aix-gcc/no-asm/openssl.gypi'],
     }, 'target_arch=="ppc" and OS=="linux"', {
       'includes': ['config/archs/linux-ppc/no-asm/openssl.gypi'],
@@ -30,8 +33,6 @@
     }, 'target_arch=="ia32"', {
       # noasm linux-elf for other ia32 platforms
       'includes': ['config/archs/linux-elf/no-asm/openssl.gypi'],
-    }, 'target_arch=="x64" and OS=="freebsd"', {
-      'includes': ['config/archs/BSD-x86_64/no-asm/openssl.gypi'],
     }, 'target_arch=="x64" and OS=="mac"', {
       'includes': ['config/archs/darwin64-x86_64-cc/no-asm/openssl.gypi'],
     }, 'target_arch=="x64" and OS=="solaris"', {
