--- common/cmd_boot.c.orig	2015-10-19 23:59:38 UTC
+++ common/cmd_boot.c
@@ -19,6 +19,15 @@ __attribute__((weak))
 unsigned long do_go_exec(ulong (*entry)(int, char * const []), int argc,
 				 char * const argv[])
 {
+	/*
+	 * FreeBSD wants the caches enabled while ubldr runs, and as of r276397
+	 * the kernel can tolerate being entered with internal (but not external
+	 * PL310) caches enabled on armv6/7 systems.  So don't disable caches
+	 * here, just invalidate the icache (because we DMA'd new data into that
+	 * memory recently) and launch the program directly.
+	 */
+	flush_dcache_all();
+	invalidate_icache_all();
 	return entry (argc, argv);
 }
 
