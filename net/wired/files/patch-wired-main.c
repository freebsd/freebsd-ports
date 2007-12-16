--- wired/main.c.orig	2007-12-16 10:36:41.000000000 +0100
+++ wired/main.c	2007-12-16 10:37:10.000000000 +0100
@@ -195,7 +195,7 @@
 
 	/* detach */
 	if(daemonize) {
-		wi_array_insert_data_at_index(arguments, WI_STR("-X"), 0);
+		wi_array_add_data(arguments, WI_STR("-X"));
 		wi_array_insert_data_at_index(arguments, wi_string_with_cstring(argv[0]), 0);
 		
 		switch(fork()) {
