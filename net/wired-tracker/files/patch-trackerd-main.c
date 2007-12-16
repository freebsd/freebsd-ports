--- trackerd/main.c.orig	2007-12-16 14:55:55.000000000 +0100
+++ trackerd/main.c	2007-12-16 14:56:27.000000000 +0100
@@ -190,7 +190,7 @@
 	
 	/* detach */
 	if(daemonize) {
-		wi_array_insert_data_at_index(arguments, WI_STR("-X"), 0);
+		wi_array_add_data(arguments, WI_STR("-X"));
 		wi_array_insert_data_at_index(arguments, wi_string_with_cstring(argv[0]), 0);
 		
 		switch(fork()) {
