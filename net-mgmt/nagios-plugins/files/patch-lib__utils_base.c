--- lib/utils_base.c.orig	Sat Jul 21 17:42:49 2007
+++ lib/utils_base.c	Sat Jul 21 17:43:07 2007
@@ -89,7 +89,7 @@
 {
 	thresholds *temp_thresholds = NULL;
 
-	temp_thresholds = malloc(sizeof(temp_thresholds));
+	temp_thresholds = malloc(sizeof(thresholds));
 
 	temp_thresholds->warning = NULL;
 	temp_thresholds->critical = NULL;
