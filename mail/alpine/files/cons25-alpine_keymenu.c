--- alpine/keymenu.c.orig	2007-12-21 01:53:12.000000000 -0800
+++ alpine/keymenu.c	2007-12-21 01:53:12.000000000 -0800
@@ -2601,7 +2601,12 @@
 	char  this_label[6*MAX_LABEL+1];
 
 	j = 6*i - 1;
+
+	/*
+	Change this line so that color works on cons25 terminals
 	if(i == 1 && !label_color)
+	*/
+	if(i == 1)
 	  max_column--;  /* Some terminals scroll if you write in the
 			    lower right hand corner. If user has a
 			    label_color set we'll take our chances.
