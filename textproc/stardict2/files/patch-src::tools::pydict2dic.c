--- src/tools/pydict2dic.c.orig	Fri Apr 25 18:55:55 2003
+++ src/tools/pydict2dic.c	Mon May  5 04:10:27 2003
@@ -24,6 +24,20 @@
 {	
 	struct stat stats;
 	FILE *pyfile,*ecidxfile,*ecdicfile,*ceidxfile,*cedicfile;
+	gchar *buffer;
+	GArray *ecarray;
+	struct _worditem ecworditem;
+	GArray *cearray;
+	struct _worditem ceworditem;
+	gchar *p1,*p2,*p3,*p4;
+	gchar *utf_str;
+	gsize write_size;
+	glong word_len;
+	long offset_old;
+	glong wordcount;
+	glong i;
+	gchar *previous_word = "";
+	struct _worditem *pworditem;
 	
 	if (stat (filename, &stats) == -1)
 	{
@@ -32,24 +46,17 @@
 	}
 	pyfile = fopen(filename,"r");
 
-	gchar *buffer;
 	buffer = (gchar *)g_malloc (stats.st_size + 2);
 	fread (buffer, 1, stats.st_size, pyfile);
 	fclose (pyfile);
 	buffer[stats.st_size] = '\n';	
 	buffer[stats.st_size+1] = '\0';	
 	
-	GArray *ecarray = g_array_sized_new(FALSE,FALSE, sizeof(struct _worditem),177785); //pydict.lib have 177785 lines.
-	struct _worditem ecworditem;
-	GArray *cearray = g_array_sized_new(FALSE,FALSE, sizeof(struct _worditem),177785);
-	struct _worditem ceworditem;
+	ecarray = g_array_sized_new(FALSE,FALSE, sizeof(struct _worditem),177785); //pydict.lib have 177785 lines.
+	cearray = g_array_sized_new(FALSE,FALSE, sizeof(struct _worditem),177785);
 	
-	gchar *p1,*p2,*p3,*p4;
 	p1 = buffer;
-	gchar *utf_str;
-	gsize write_size;
-	glong word_len;
-	
+
 	while (1) {
 		if (*p1=='\0') {
 			g_print("over\n");
@@ -142,12 +149,6 @@
 	fprintf(ceidxfile,"stardict's idx file\ndictfile=pydict-big5-ce.dict\nbookname=pydict-big5-ce\nbeigin:\n");
 	*/
 	
-	long offset_old;
-	
-	glong wordcount;
-	glong i;
-	gchar *previous_word = "";
-	struct _worditem *pworditem;
 	
 	wordcount = ecarray->len;
 	for (i=0;i<ecarray->len;i++)
