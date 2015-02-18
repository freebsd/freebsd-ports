--- pwc-dec23.c.orig	2006-06-04 05:39:14.000000000 +0400
+++ pwc-dec23.c	2015-02-16 22:09:58.000000000 +0300
@@ -261,7 +261,7 @@
 {
 	int flags;
 	struct pwc_dec23_private *pdev = data;
-	release = release;
+	/* release = release; */
 
 	switch (type) {
 	case 720:
@@ -277,7 +277,7 @@
 			pdev->zz = 6;
 		flags = mode[2] >> 5;	/* our: 7 */
 
-		fill_table_color(flags, (unsigned int *)KiaraRomTable,
+		fill_table_color(flags, (const unsigned int *)KiaraRomTable,
 				 pdev->table_0004, pdev->table_8004);
 		break;
 
@@ -293,7 +293,7 @@
 			pdev->zz = 6;
 		flags = mode[2] >> 3;
 
-		fill_table_color(flags, (unsigned int *)TimonRomTable,
+		fill_table_color(flags, (const unsigned int *)TimonRomTable,
 				 pdev->table_0004, pdev->table_8004);
 		break;
 
