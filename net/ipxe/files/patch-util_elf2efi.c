--- util/elf2efi.c.orig	2018-02-27 10:48:55 UTC
+++ util/elf2efi.c
@@ -73,7 +73,7 @@
 #define ELF_MREL( mach, type ) ( (mach) | ( (type) << 16 ) )
 
 /* Allow for building with older versions of elf.h */
-#ifndef EM_AARCH64
+#if !defined(EM_AARCH64) || defined(__FreeBSD__)
 #define EM_AARCH64 183
 #define R_AARCH64_NONE 0
 #define R_AARCH64_ABS64 257
