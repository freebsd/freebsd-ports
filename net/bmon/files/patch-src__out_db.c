--- ./src/out_db.c.orig	2008-03-24 22:44:47.000000000 -0400
+++ ./src/out_db.c	2008-03-24 22:45:03.000000000 -0400
@@ -679,7 +679,7 @@
 	.om_draw = db_draw,
 	.om_set_opts = db_set_opts,
 	.om_probe = db_probe,
-	.om_shutdown db_shutdown,
+	.om_shutdown = db_shutdown,
 };
 
 static void __init db_init(void)
