
$FreeBSD$

--- sdd/sdd.c.orig	Fri Sep 17 02:28:51 2004
+++ sdd/sdd.c	Fri Sep 17 02:30:12 2004
@@ -1654,11 +1654,13 @@
 usage(ex)
 	int ex;
 {
-	error("\
+	FILE *fp = ex ? stderr : stdout;
+
+	fprintf(fp, "\
 Usage:	sdd [option=value] [-flag]\n\
 Options:\n\
 ");
-	error("\
+	fprintf(fp, "\
 	if=name		  Read  input from name instead of stdin\n\
 	of=name		  Write output to name instead of stdout\n\
 	-inull		  Do not read input from file (use null char's)\n\
@@ -1672,7 +1674,7 @@
 	seek=#,skip=#	  Seek/skip # bytes on input/output before starting\n\
 	ivseek=#,ovseek=# Seek # bytes on input/output volumes before starting\n\
 ");
-	error("\
+	fprintf(fp, "\
 	-notrunc	  Do not trunctate existing output file\n\
 	-pg		  Print a dot on each write to indicate progress\n\
 	-noerror	  Do not stop on error\n\
@@ -1683,8 +1685,8 @@
 	-fill		  Fill each record with zeros up to obs\n\
 	-swab,-block,-unblock,-lcase,-ucase,-ascii,-ebcdic,-ibm\n\
 ");
-	error("\t-help\t\t  print this online help\n");
-	error("\t-version\t  print version number\n");
+	fprintf(fp, "\t-help\t\t  print this online help\n");
+	fprintf(fp, "\t-version\t  print version number\n");
 	exit(ex);
 }
 
