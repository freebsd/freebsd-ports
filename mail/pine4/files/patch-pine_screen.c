--- pine/screen.c.orig	Wed Apr  7 10:35:42 2004
+++ pine/screen.c	Tue Aug 10 22:35:37 2004
@@ -208,7 +208,12 @@
 	char  this_label[MAX_LABEL+1];
 
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
