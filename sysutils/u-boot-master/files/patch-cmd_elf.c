--- cmd/elf.c.orig	2018-01-09 01:25:29 UTC
+++ cmd/elf.c
@@ -109,6 +109,11 @@ static unsigned long do_bootelf_exec(ulong (*entry)(in
 {
 	unsigned long ret;
 
+	if (dcache_status())
+		flush_dcache_all();
+	if (icache_status())
+		invalidate_icache_all();
+
 	/*
 	 * pass address parameter as argv[0] (aka command name),
 	 * and all remaining args
