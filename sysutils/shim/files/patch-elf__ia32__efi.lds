--- elf_ia32_efi.lds.orig	2018-12-15 14:43:25 UTC
+++ elf_ia32_efi.lds
@@ -1,4 +1,4 @@
-OUTPUT_FORMAT("elf32-i386", "elf32-i386", "elf32-i386")
+OUTPUT_FORMAT("elf32-i386-freebsd", "elf32-i386-freebsd", "elf32-i386-freebsd")
 OUTPUT_ARCH(i386)
 ENTRY(_start)
 SECTIONS
