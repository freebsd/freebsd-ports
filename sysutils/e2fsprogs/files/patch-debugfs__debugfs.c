--- ./debugfs/debugfs.c.orig	2012-03-26 19:36:24.000000000 +0200
+++ ./debugfs/debugfs.c	2012-04-01 17:34:53.000000000 +0200
@@ -1000,7 +1000,7 @@
 
 	if (common_args_process(argc, argv, 2, 3, argv[0], "<file> [num]",
 				CHECK_FS_RW | CHECK_FS_BITMAPS))
-		return 1;
+		return;
 	if (check_fs_read_write(argv[0]))
 		return;
 
