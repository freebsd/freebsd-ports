--- vnconvert.c.orig	1994-05-20 20:36:17 UTC
+++ vnconvert.c
@@ -91,7 +91,7 @@ main()
 		printf("\t6 - VN Thin-Art (Mac)\n\n");
 
 		printf("Input-file name (or Enter to quit): ");
-		gets(bufline);
+		gets_s(bufline, 255);
 		if (strlen(bufline) == 0)
 			break;
 		sscanf(bufline, "%s", input_file);
@@ -99,21 +99,21 @@ main()
 		printf("currently in the format number: ");
 		*bufline = '\0'; 
 		while (strlen(bufline)==0) {
-			gets(bufline);
+			gets_s(bufline, 255);
 			sscanf(bufline, "%d", &from);
 		}
 
 		printf("\nOutput-file name: ");
 		*bufline = '\0';
                 while (strlen(bufline)==0) {
-                        gets(bufline);
+                        gets_s(bufline, 255);
                         sscanf(bufline, "%s", output_file); 
                 }
 
 		printf("to the format number: ");
 		*bufline = '\0';
                 while (strlen(bufline)==0) {
-                        gets(bufline);
+                        gets_s(bufline, 255);
                         sscanf(bufline, "%d", &to);
                 }
 
@@ -152,7 +152,7 @@ main()
 			}
 			else {
 				fprintf(stderr, "\"%s\" already exists. Overwrite it (y/n)? ", output_file);
-				gets(buf);
+				gets_s(buf, BUFSIZ);
 				if (toupper(buf[0]) != 'Y')  
 					icontinue = 1;
 			}
