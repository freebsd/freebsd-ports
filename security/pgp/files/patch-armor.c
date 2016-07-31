--- armor.c.orig	1996-01-17 19:37:20 UTC
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
