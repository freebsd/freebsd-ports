--- wmcube.c.orig	Mon Oct 23 22:11:47 2000
+++ wmcube.c	Tue May 15 16:17:02 2001
@@ -913,7 +926,7 @@ int loadobj(char *filename) {
 		exit(0);
 	}
 
-	fscanf(fp,"%s",tmp);
+	fscanf(fp,"%63s",tmp);
 	
 	if (strcmp(tmp,"WMCUBE_COORDINATES") != 0) { 
 		printf("\nError in objectfile: it must start with WMCUBE_COORDINATES\n\n");
@@ -921,7 +934,7 @@ int loadobj(char *filename) {
 		exit(0);
 	}
 
-	fscanf(fp,"%s",tmp);
+	fscanf(fp,"%63s",tmp);
 	counter = atoi(tmp);
 
 	while ((strcmp(tmp,"WMCUBE_LINES") != 0) && (strcmp(tmp,"WMCUBE_PLANES") != 0)) {		
@@ -938,7 +951,7 @@ int loadobj(char *filename) {
 			fclose(fp);
 			exit(0);
 		}
-		fscanf(fp,"%s",tmp);
+		fscanf(fp,"%63s",tmp);
 
 		if (feof(fp)) {
 			printf("\nError in objectfile: you must have a section WMCUBE_LINES or WMCUBE_PLANES\n\n");
