--- panel.c.orig	Sun Dec 16 19:11:01 2001
+++ panel.c	Mon Dec 17 20:28:33 2001
@@ -221,7 +221,7 @@
 	char *data;
 
 	strcpy (tmpname, "/tmp/wmessage.XXXXXX");	/* last 6 chars must be X */
-	mktemp (tmpname);
+	mkstemp (tmpname);
 
 	if (!tmpname)
 		return NULL;	/* couldn't generate unique name */
@@ -344,12 +344,12 @@
 			int i, j=0, lines=0, longest=0;
 
 			msg = readFile (panel, settings);
-			if (msg == NULL)
+			if (msg == NULL) {
 				if ((settings->reload > 0) && (settings->force == True))
 					msg = wstrdup ("Cannot open file -- will keep trying.\n");
 				else
 					return NULL;
-
+			}
 			for (i = 0; i < strlen (msg); i++) /* count lines */
 				if ((*(msg+i)) == '\n') {
 					lines++;
