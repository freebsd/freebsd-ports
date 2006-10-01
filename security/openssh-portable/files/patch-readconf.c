--- readconf.c.orig	Fri Sep  1 02:38:37 2006
+++ readconf.c	Sat Sep 30 10:38:05 2006
@@ -1112,7 +1122,7 @@
 	if (options->batch_mode == -1)
 		options->batch_mode = 0;
 	if (options->check_host_ip == -1)
-		options->check_host_ip = 1;
+		options->check_host_ip = 0;
 	if (options->strict_host_key_checking == -1)
 		options->strict_host_key_checking = 2;	/* 2 is default */
 	if (options->compression == -1)
