--- common/cmd_elf.c.orig	2016-01-12 14:06:54 UTC
+++ common/cmd_elf.c
@@ -110,22 +110,15 @@ static unsigned long do_bootelf_exec(ulo
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
 
