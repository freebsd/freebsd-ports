--- LaTeX.c.orig	Sun Jul  3 11:23:45 2005
+++ LaTeX.c	Sun Jul  3 11:24:29 2005
@@ -77,13 +77,13 @@
 	
   while(ptr1 != NULL)
     {
-      retro = FALSE;
       char *tex, *message, *idstring;
       gchar *name, *buf;
       char *filedata;
       size_t size;
       GError *error = NULL;
       char *filter;
+      retro = FALSE;
 
       pos1 = strlen(*tmp2) - strlen(ptr1);
 		
