--- ohuman.c.orig	Sun Feb 27 11:08:01 2005
+++ ohuman.c	Fri Nov 11 09:58:37 2005
@@ -3,9 +3,9 @@
 
 void ohuman_print(struct dvd_info *dvd_info) {
 
+	int i, j;
 	printf("Disc Title: %s\n", dvd_info->discinfo.disc_title);
 
-	int i, j;
 	for (j=0; j < dvd_info->title_count; j++) 
 	{
 	if ( opt_t == j+1 || opt_t == 0 ) {
