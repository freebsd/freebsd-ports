--- src/amyc_prefs.c.orig	Fri Jun  8 18:21:45 2001
+++ src/amyc_prefs.c	Sun Jun 10 10:09:42 2001
@@ -126,7 +126,7 @@
     }
     if (prefs->resultdirectory == NULL) {
 	prefs->resultdirectory = malloc (LINE_LEN * sizeof (char));
-	sprintf (prefs->resultdirectory, "%s", "/tmp");
+	sprintf (prefs->resultdirectory, "%s", getenv("HOME"));
 	used_default_value = 1;
     }
 
@@ -307,6 +307,7 @@
 	sprintf (filename, "%s/result.html", prefs->resultdirectory);
 	strtmp = give_correct_path ((char *)filename);
 	output = fopen (strtmp, "w");
+	printf ("Dumping results to %s\n", filename);
 	if (output == NULL) {
 	    perror (strtmp);
 #warning TOTO: better error handling
