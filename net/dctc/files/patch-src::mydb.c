--- src/mydb.c.orig	Mon Jul 22 13:48:07 2002
+++ src/mydb.c	Mon Jul 22 19:21:42 2002
@@ -1141,6 +1141,16 @@
 int file_in_db(char *filename, int *virtual)
 {
 	int i;
+	char *filename_internal;
+
+	if ((filename != NULL) && (filename[0]=='/'))
+	{
+		if(hide_absolute==0)
+			filename_internal=filename;
+		else
+			filename_internal=filename+1;
+	} else
+			filename_internal=filename;
 
 	G_LOCK(shared_info);
 	if(shared_info!=NULL)
@@ -1151,7 +1161,7 @@
 
 			/* DB_ENTRY to compare */
 			de=&(g_array_index(shared_info,DB_ENTRY,i));
-			if(!strcmp(de->filename,filename))
+			if(!strcmp(de->filename,filename_internal))
 			{
 				*virtual=de->virtual;
 				G_UNLOCK(shared_info);
