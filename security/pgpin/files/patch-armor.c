--- armor.c.orig	1998-01-12 08:13:03 UTC
+++ armor.c
@@ -343,7 +343,7 @@ copyline(FILE * in, FILE * out)
  * idea.
  */
 static int
-getline(char *buf, int n, FILE * f)
+get_line(char *buf, int n, FILE * f)
 {
     int state;
     char *p;
@@ -376,7 +376,7 @@ getline(char *buf, int n, FILE * f)
 	    return 0;		/* Out of buffer space */
 	}
     }				/* for (;;) */
-}				/* getline */
+}				/* get_line */
 
 #if 1
 /* This limit is advisory only; longer lines are handled properly.
@@ -547,7 +547,7 @@ armor_file(char *infilename, char *outfi
 	    return 1;
 	}
 	fprintf(outFile, "-----BEGIN PGP SIGNED MESSAGE-----\n\n");
-	while ((i = getline(buffer, sizeof buffer, clearFile)) >= 0) {
+	while ((i = get_line(buffer, sizeof buffer, clearFile)) >= 0) {
 	    /* Quote lines beginning with '-' as per RFC1113;
 	     * Also quote lines beginning with "From "; this is
 	     * for Unix mailers which add ">" to such lines.
@@ -1231,7 +1231,7 @@ LANG("\n\007Unable to write ciphertext o
 	for (;;) {
 	    ++infile_line;
 	    nline = status;
-	    status = getline(buf, sizeof buf, in);
+	    status = get_line(buf, sizeof buf, in);
 	    if (status < 0) {
 		fprintf(pgpout,
 LANG("ERROR: ASCII armor decode input ended unexpectedly!\n"));
@@ -1249,7 +1249,7 @@ LANG("ERROR: ASCII armor decode input en
 	    /* Copy trailing part of line, if any. */
 	    if (!status)
 		status = copyline(in, litout);
-	    /* Ignore error; getline will discover it again */
+	    /* Ignore error; get_line will discover it again */
 	}
 	fflush(litout);
 	if (ferror(litout)) {
