--- src/filehandling_functions.c.orig	Fri Mar 17 00:15:02 2006
+++ src/filehandling_functions.c	Fri Mar 17 15:57:06 2006
@@ -139,14 +139,13 @@
 	char name[256];
 	char file[256];
 	int i;
+	char *nameend, *filestart, *fileend, *dot;
 	
 	id = opendirfile(0);
 	if (!id)
 		return 0;
 	
 	read_item(id, type, message, lines);
-
-	char *nameend, *filestart, *fileend, *dot;
 	
 	/* search for node-links in every line */
 	for (i = 1; i < Lines; i++)
@@ -163,6 +162,7 @@
 
 			/* skip this hit if it is not a perfect match and 
 			 * we have already found a previous partial match */
+			char *tmp = name;
 			if ( ! ( (nameend - Message[i]) - 2 == filenamelen ) 
 					&&	goodHit )
 			{
@@ -170,7 +170,6 @@
 			}
 
 			/* find the name of the node link */
-			char *tmp = name;
 			strncpy(file, filestart + 1, fileend - filestart - 1);
 			file[fileend - filestart - 1] = 0;
 			strncpy(name, fileend + 1, dot - fileend - 1);
