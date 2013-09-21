--- ./libpkg/private/elf_tables.h.orig	2013-07-06 12:48:19.000000000 +0200
+++ ./libpkg/private/elf_tables.h	2013-09-19 21:52:03.661029778 +0200
@@ -59,7 +59,9 @@
 	{ -1, NULL }
 };
 
-#define EF_MIPS_ABI	0x0000F000
+#ifndef EF_MIPS_ABI
+#define EF_MIPS_ABI	0x0000f000
+#endif
 #define E_MIPS_ABI_O32	0x00001000
 #define E_MIPS_ABI_N32	0x00000020
 
