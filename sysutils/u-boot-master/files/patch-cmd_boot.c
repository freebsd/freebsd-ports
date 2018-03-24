--- cmd/boot.c.orig	2018-01-09 01:25:29 UTC
+++ cmd/boot.c
@@ -19,6 +19,10 @@ __attribute__((weak))
 unsigned long do_go_exec(ulong (*entry)(int, char * const []), int argc,
 				 char * const argv[])
 {
+	if (dcache_status())
+		flush_dcache_all();
+	if (icache_status())
+		invalidate_icache_all();
 	return entry (argc, argv);
 }
 
