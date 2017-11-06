--- UTC
base defaults

r99048 | des | 2002-06-29 05:51:56 -0500 (Sat, 29 Jun 2002) | 4 lines
Changed paths:
   M /head/crypto/openssh/myproposal.h
   M /head/crypto/openssh/readconf.c
   M /head/crypto/openssh/servconf.c

Apply FreeBSD's configuration defaults.

--- readconf.c.orig	2014-07-17 23:11:26.000000000 -0500
+++ readconf.c	2014-11-03 16:45:05.188796445 -0600
@@ -1934,7 +1946,7 @@ fill_default_options(Options * options)
 	if (options->batch_mode == -1)
 		options->batch_mode = 0;
 	if (options->check_host_ip == -1)
-		options->check_host_ip = 1;
+		options->check_host_ip = 0;
 	if (options->strict_host_key_checking == -1)
 		options->strict_host_key_checking = 2;	/* 2 is default */
 	if (options->compression == -1)
