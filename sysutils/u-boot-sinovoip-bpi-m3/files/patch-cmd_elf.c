--- cmd/elf.c.orig	2016-04-12 02:22:25 UTC
+++ cmd/elf.c
@@ -110,22 +110,12 @@ static unsigned long do_bootelf_exec(ulo
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
 
