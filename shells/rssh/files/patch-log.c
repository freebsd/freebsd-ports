Workaround for basename(3) that is POSIX compliant since r308264 in FreeBSD 12
--- log.c.orig	2012-11-27 00:25:13 UTC
+++ log.c
@@ -93,10 +93,14 @@ char *log_make_ident( const char *name )
 	}
 	/* assign new value to ident from name */
 	if ( !name ) return (ident = NULL);
-	ident = strdup(basename((char*)name));
-	/* remove leading '-' from ident, if there is one */
-	if ( ident[0] == '-' ){
-		temp = strdup(ident + 1);
+	/* clone name in case basename() is POSIX-compliant */
+	temp = strdup ((char *) name);
+	/* always pass writeable string to basename() */
+	ident = strdup (basename (temp));
+	free (temp);
+	/* safely remove leading '-' from ident, if there is one */
+	if ((ident != NULL) && (ident[0] == '-')){
+		temp = strdup(&ident[1]);
 		free(ident);
 		ident = temp;
 	}
