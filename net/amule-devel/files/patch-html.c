--- src/utils/cas/html.c.orig	Wed Sep 29 01:21:07 2004
+++ src/utils/cas/html.c	Sat Oct 23 04:30:24 2004
@@ -50,11 +50,6 @@
 	FILE *temp;
 
 
-	snprintf(version, 25, "cas %s", CAS_VERSION);
-	snprintf(upload, 25, "%s kB/s", stats[6]);
-	snprintf(download, 25, "%s kB/s", stats[5]);
-
-
 	char *search[] = {"#VERSION#", "#CLIENT#", "#NICK#", "#UPLOADRATE#" ,
 		"#DOWNLOADRATE#" , "#QUEUE#" , "#NUMSHARE#" , "#SESSIONUP#" ,
 		"#SESSIONDOWN#" , "#TOTALUP#", "#TOTALDOWN#" , "#SERVER#" , "#IP#",
@@ -63,6 +58,11 @@
 	char *repl[] = { version , lines[0] , stats[9] , upload , download ,
 		stats[7] , stats[8] , stats[14] , stats[13] , stats[11] , stats[10] ,
 		stats[1] , stats[2] , stats[3] };
+
+
+	snprintf(version, 25, "cas %s", CAS_VERSION);
+	snprintf(upload, 25, "%s kB/s", stats[6]);
+	snprintf(download, 25, "%s kB/s", stats[5]);
 
 	// get some memory to read the template into
 	if ((fd = open (template, O_RDONLY)) < 0)
