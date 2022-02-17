--- libpkg/private/elf_tables.h.orig	2021-11-12 08:57:25 UTC
+++ libpkg/private/elf_tables.h
@@ -98,6 +98,7 @@ static struct arch_trans machine_arch_translation[] = 
 	{ "armv7:32:el:eabi:softfp", "armv7" },
 	{ "armv7:32:el:eabi:hardfp", "armv7" },
 	{ "aarch64:64", "aarch64" },
+	{ "aarch64:64:cheri", "aarch64c" },
 	/* And now MIPS */
 	{ "mips:32:el:o32", "mipsel" },
 	{ "mips:32:el:n32", "mipsn32el" },
@@ -109,6 +110,7 @@ static struct arch_trans machine_arch_translation[] = 
 	{ "riscv:32:hf", "riscv32" },
 	{ "riscv:32:sf", "riscv32sf" },
 	{ "riscv:64:hf", "riscv64" },
+	{ "riscv:64:cheri:hf", "riscv64c" },
 	{ "riscv:64:sf", "riscv64sf" },
 
 	{ NULL, NULL }
