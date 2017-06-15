--- refer/refer7.c.orig	2016-03-09 21:27:38 UTC
+++ refer/refer7.c
@@ -56,16 +56,21 @@ dumpold(void)
 
 	if (!endpush)
 		return;
-	fclose(fo);
-	fo = NULL;
+	if (fo != NULL) {
+		fclose(fo);
+		fo = NULL;
+	}
+	fi = fopen(tfile, "r");
+	if (fi == NULL)
+		return;
 	if (sort) {
 		char comm[100];
+
+		fclose(fi);
 		snprintf(comm, sizeof(comm), "sort -f %s -o %s", tfile, tfile);
 		system(comm);
+		fi = fopen(tfile, "r");
 	}
-	fi = fopen(tfile, "r");
-	if (fi == NULL)
-		return;
 	flout();
 	fprintf(ftemp, ".]<\n");
 	while ((c = getc(fi)) > 0) {
