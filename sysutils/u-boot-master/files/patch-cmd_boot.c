--- cmd/boot.c.orig	2018-07-09 14:24:14 UTC
+++ cmd/boot.c
@@ -18,6 +18,10 @@ __attribute__((weak))
 unsigned long do_go_exec(ulong (*entry)(int, char * const []), int argc,
 				 char * const argv[])
 {
+	if (dcache_status())
+		flush_dcache_all();
+	if (icache_status())
+		invalidate_icache_all();
 	return entry (argc, argv);
 }
 
