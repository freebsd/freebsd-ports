--- main.c.orig	Wed Mar  1 21:56:27 2000
+++ main.c	Tue May 15 14:44:34 2001
@@ -20,7 +20,7 @@
 
 #include <tcl.h>
 #include <tk.h>
-#include <malloc.h>
+#include <stdlib.h>
 #include <locale.h>
 #include <assert.h>
 #include <time.h>
@@ -145,7 +145,7 @@
 	char buffer[128];  
 	FILE *file; 
 	int v1, v2, v3;
-	if ( ( file=popen( "rat -version", "rt") )!=NULL ) {
+	if ( ( file=popen( "rat30 -version", "rt") )!=NULL ) {
 		fgets(buffer, sizeof(buffer), file);
 		pclose(file);
 		/* get version */
