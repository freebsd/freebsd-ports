--- common/cmd_elf.c.orig	2014-08-14 14:51:10 UTC
+++ common/cmd_elf.c
@@ -46,6 +46,7 @@ unsigned long do_bootelf_exec(ulong (*en
 	 * pass address parameter as argv[0] (aka command name),
 	 * and all remaining args
 	 */
+	cleanup_before_linux();
 	ret = entry(argc, argv);
 
 	if (dcache)
