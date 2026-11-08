--- wmcube.c.orig	2016-02-28 22:58:41 UTC
+++ wmcube.c
@@ -56,7 +56,6 @@
 #include <sys/ioctl.h>
 #include <sys/socket.h>
 
-#include <utmp.h>
 #include <dirent.h>
 
 #include <X11/Xlib.h>
@@ -407,7 +406,7 @@ void set_plugin()
 {
 	strcpy(obj_filename,plugin);
 	if (access (obj_filename, R_OK) == -1) {
-		strcpy(obj_filename,"/usr/share/wmcube/");
+		strcpy(obj_filename,"/usr/local/share/wmcube/");
 		strcat(obj_filename,plugin);
 	}
 }
@@ -997,7 +996,7 @@ int loadobj(char *filename) {
 		exit(0);
 	}
 
-	if (fscanf(fp,"%s",tmp) < 1)
+	if (fscanf(fp,"%63s",tmp) < 1)
 		printf("WARNING: Could not read first line of object-file (%s).\n",filename);
 	
 	if (strcmp(tmp,"WMCUBE_COORDINATES") != 0) {
@@ -1006,7 +1005,7 @@ int loadobj(char *filename) {
 		exit(0);
 	}
 
-	if (fscanf(fp,"%s",tmp) < 1)
+	if (fscanf(fp,"%63s",tmp) < 1)
 		printf("WARNING: Could not read second line of object-file (%s).\n",filename);
 
 	while ((strcmp(tmp,"WMCUBE_LINES") != 0) && (strcmp(tmp,"WMCUBE_PLANES") != 0)) {		
@@ -1024,7 +1023,7 @@ int loadobj(char *filename) {
 			fclose(fp);
 			exit(0);
 		}
-		if (fscanf(fp,"%s",tmp) < 1)
+		if (fscanf(fp,"%63s",tmp) < 1)
 			printf("WARNING: Could not read next line of object-file (%s).\n",filename);
 
 		if (feof(fp)) {
