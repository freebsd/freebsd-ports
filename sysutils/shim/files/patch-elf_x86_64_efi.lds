--- elf_x86_64_efi.lds.orig	2015-06-30 18:20:12 UTC
+++ elf_x86_64_efi.lds
@@ -1,5 +1,5 @@
-/* Same as elf_x86_64_fbsd_efi.lds, except for OUTPUT_FORMAT below - KEEP IN SYNC */
-OUTPUT_FORMAT("elf64-x86-64", "elf64-x86-64", "elf64-x86-64")
+/* Same as elf_x86_64_efi.lds, except for OUTPUT_FORMAT below - KEEP IN SYNC */
+OUTPUT_FORMAT("elf64-x86-64-freebsd", "elf64-x86-64-freebsd", "elf64-x86-64-freebsd")
 OUTPUT_ARCH(i386:x86-64)
 ENTRY(_start)
 SECTIONS
