--- https.c.orig	2013-09-20 23:17:00.000000000 +0200
+++ https.c	2015-02-27 12:35:41.718975799 +0100
@@ -36,7 +36,7 @@
 		unsigned os_pool_size;
 
 		const unsigned char *f = (const unsigned char *)RAND_file_name(cast_char f_randfile, sizeof(f_randfile));
-		if (f && RAND_egd(cast_const_char f) < 0) {
+		if (f) {
 			/* Not an EGD, so read and write to it */
 			if (RAND_load_file(cast_const_char f_randfile, -1))
 				RAND_write_file(cast_const_char f_randfile);
