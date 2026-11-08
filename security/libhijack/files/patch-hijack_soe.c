--- hijack/soe.c.orig	2025-10-26 01:32:34 UTC
+++ hijack/soe.c
@@ -36,6 +36,8 @@
 #include <sys/types.h>
 #include <sys/mman.h>
 
+#include <sys/param.h>  /* This defines __FreeBSD_version */
+
 #include "hijack.h"
 #include "hijack_prog.h"
 
@@ -94,7 +96,11 @@ iterate_object_entries(HIJACK *ctx, Obj_Entry *soe)
 	    (unsigned long)(soe->entry));
 	printf("[SOE] phdr: 0x%016lx\n",
 	    (unsigned long)(soe->phdr));
-	printf("[SOE] phsize: %zu\n", soe->phsize);
+#if __FreeBSD_version >= 1500508
+	printf("[SOE] phsize: %zu\n", soe->phnum * sizeof(Elf_Phdr));
+#else
+	printf("[SOE] phsize: %zu\n", soe->phsize);
+#endif
 	fetch_and_print_string(ctx, "interp", (void *)(soe->interp));
 	printf("[SOE] stack_flags: %x\n", soe->stack_flags);
 	printf("[SOE] tlsindex: %d\n", soe->tlsindex);
