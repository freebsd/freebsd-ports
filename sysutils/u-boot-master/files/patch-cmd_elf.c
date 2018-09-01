--- cmd/elf.c.orig	2018-07-09 14:24:14 UTC
+++ cmd/elf.c
@@ -153,6 +153,11 @@ static unsigned long do_bootelf_exec(ulong (*entry)(in
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
