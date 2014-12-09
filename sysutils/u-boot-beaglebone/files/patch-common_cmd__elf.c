--- common/cmd_elf.c.orig	2014-10-14 08:47:15 UTC
+++ common/cmd_elf.c
@@ -46,6 +46,7 @@ unsigned long do_bootelf_exec(ulong (*en
 	 * pass address parameter as argv[0] (aka command name),
 	 * and all remaining args
 	 */
+	cleanup_before_linux();
 	ret = entry(argc, argv);
 
 	if (dcache)
