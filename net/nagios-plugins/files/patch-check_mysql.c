--- plugins/check_mysql.c.orig	Fri Nov 15 02:04:51 2002
+++ plugins/check_mysql.c	Tue Nov 26 15:12:58 2002
@@ -207,7 +207,7 @@
 	if (strlen(db) == 0 && argc > c)
 		db = argv[c++];
 
-	if (is_intnonneg (argv[c]))
+	if (argc > c && is_intnonneg (argv[c]))
 		db_port = atoi (argv[c++]);
 
 	return validate_arguments ();
