--- alpine/keymenu.c.orig	2013-08-15 04:36:01.000000000 +0000
+++ alpine/keymenu.c
@@ -2774,7 +2774,11 @@ output_keymenu(struct key_menu *km, unsi
 
 	j = 6*i - 1;
 #ifndef __CYGWIN__
-	if(i == 1 && !label_color)
+	/*
+	 * Change this line so that color works on cons25 terminals
+	 * if(i == 1 && !label_color)
+	 */
+	if (i == 1)
 #else
 	if(i == 1 && (!label_color || !struncmp(term_name,"cygwin", 6)))
 #endif
