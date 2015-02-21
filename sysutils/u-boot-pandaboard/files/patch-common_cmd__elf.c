--- common/cmd_elf.c.orig	2014-10-14 08:47:15 UTC
+++ common/cmd_elf.c
@@ -35,22 +35,12 @@ unsigned long do_bootelf_exec(ulong (*en
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
+	 * here, just launch the program directly.
 	 */
 	ret = entry(argc, argv);
-
-	if (dcache)
-		dcache_enable();
-
 	return ret;
 }
 
