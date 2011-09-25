--- rdup-tr.c.orig	2011-02-20 01:30:07.000000000 +0300
+++ rdup-tr.c	2011-09-25 11:36:39.000000000 +0400
@@ -202,7 +202,6 @@
 		if (sig != 0)
 			signal_abort(sig);
 
-		rdup_entry = rdup_entry;
 #ifdef HAVE_LIBNETTLE
 		if (opt_crypt_key)
 			rdup_entry = crypt_entry(rdup_entry, trhash);
