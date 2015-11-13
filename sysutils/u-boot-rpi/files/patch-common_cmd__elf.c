--- common/cmd_elf.c.orig	2015-10-19 23:59:38 UTC
+++ common/cmd_elf.c
@@ -35,22 +35,15 @@ static unsigned long do_bootelf_exec(ulo
 	unsigned long ret;
 
 	/*
-	 * QNX images require the data cache is disabled.
-	 * Data cache is already flushed, so just turn it off.
-	 */
-	int dcache = dcache_status();
-	if (dcache)
-		dcache_disable();
-
-	/*
-	 * pass address parameter as argv[0] (aka command name),
-	 * and all remaining args
+	 * FreeBSD wants the caches enabled while ubldr runs, and as of r276397
+	 * the kernel can tolerate being entered with internal (but not external
+	 * PL310) caches enabled on armv6/7 systems.  So don't disable caches
+	 * here, just invalidate the icache (because we DMA'd new data into that
+	 * memory recently) and launch the program directly.
 	 */
+	flush_dcache_all();
+	invalidate_icache_all();
 	ret = entry(argc, argv);
-
-	if (dcache)
-		dcache_enable();
-
 	return ret;
 }
 
