--- src/tools/oxford2dic.c.orig	Mon May  5 04:05:50 2003
+++ src/tools/oxford2dic.c	Mon May  5 04:08:14 2003
@@ -24,6 +24,19 @@
 {	
 	struct stat stats;
 	FILE *oxfile,*idxfile,*dicfile;
+	gchar *buffer;
+	gchar *p1,*p2;
+	glong line_num = 0;
+	gchar *utf_str;
+	gsize write_size;
+	struct _worditem worditem;
+	GArray *array;
+	glong tmpglong=0;
+	long offset_old;
+	glong wordcount;
+	glong i;
+	gchar *previous_word = "";
+	struct _worditem *pworditem;
 	
 	if (stat (filename, &stats) == -1)
 	{
@@ -32,21 +45,15 @@
 	}
 	oxfile = fopen(filename,"r");
 
-	gchar *buffer;
 	buffer = (gchar *)g_malloc (stats.st_size + 2);
 	fread (buffer, 1, stats.st_size, oxfile);
 	fclose (oxfile);
 	buffer[stats.st_size] = '\n';	
 	buffer[stats.st_size+1] = '\0';	
 	
-	GArray *array = g_array_sized_new(FALSE,FALSE, sizeof(struct _worditem),39000); //oxford.txt have 77304 lines.
-	struct _worditem worditem;
+	array = g_array_sized_new(FALSE,FALSE, sizeof(struct _worditem),39000); //oxford.txt have 77304 lines.
 	
-	gchar *p1,*p2;
-	glong line_num = 0;
 	p1 = buffer;
-	gchar *utf_str;
-	gsize write_size;
 	
 	while (1) {
 		if (*p1=='\0') {
@@ -91,17 +98,11 @@
 	idxfile = fopen("oxford.idxdata","w");
 	dicfile = fopen("oxford.dict","w");
 
-	glong tmpglong=0;
 	fwrite(&(tmpglong),sizeof(glong),1,idxfile);
 	
 
 	
-	long offset_old;
-	
-	glong wordcount = array->len;
-	glong i;
-	gchar *previous_word = "";
-	struct _worditem *pworditem;
+	wordcount = array->len;
 	for (i=0;i<array->len;i++)
 	{
 		pworditem = &g_array_index(array, struct _worditem, i);
