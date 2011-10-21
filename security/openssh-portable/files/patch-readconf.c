--- readconf.c.orig	2010-08-03 00:04:46.000000000 -0600
+++ readconf.c	2010-09-14 16:14:12.000000000 -0600
@@ -1169,7 +1169,7 @@
 	if (options->batch_mode == -1)
 		options->batch_mode = 0;
 	if (options->check_host_ip == -1)
-		options->check_host_ip = 1;
+		options->check_host_ip = 0;
 	if (options->strict_host_key_checking == -1)
 		options->strict_host_key_checking = 2;	/* 2 is default */
 	if (options->compression == -1)
