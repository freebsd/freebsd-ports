--- stegdeimage.c.orig	2004-08-29 23:11:00 UTC
+++ stegdeimage.c
@@ -70,9 +70,6 @@ dodeimage(char *file1, char *file2)
 	struct jpeg_error_mgr dsterr;
 	FILE *fp;
 
-	if (jpg_open("/home/stego_analysis/compress/dscf0033.jpg") == -1)
-		return;
-
 	for (comp = 0; comp < 3; comp++) {
 		ohib[comp] = hib[comp];
 		owib[comp] = wib[comp];
