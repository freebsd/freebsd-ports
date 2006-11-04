--- gui_monty.c.orig	Thu Nov 24 13:58:48 2005
+++ gui_monty.c	Thu Nov  2 00:13:29 2006
@@ -492,6 +492,7 @@
   FILE *fp;
   struct model_pak *model = data;
   gchar *last_dirsep, *yes, *no;
+  gchar **hkls, **supersats, **out_dirs;
   gint i;
   
   yes = g_strdup("yes");
@@ -513,7 +514,7 @@
   g_strstrip(model->monty.hkls);
   
   /* split the string by endline characters */
-  gchar **hkls = g_strsplit(model->monty.hkls, "\n", INT_MAX);  
+  hkls = g_strsplit(model->monty.hkls, "\n", INT_MAX);  
   
   /* print all hkl values to the file */
   for (i = 0; *(hkls+i); ++i)
@@ -523,7 +524,7 @@
   
   /* remove any whitespace, this also includes trailing \n characters */
   g_strstrip(model->monty.supersaturations);
-  gchar **supersats = g_strsplit(model->monty.supersaturations, "\n", INT_MAX);
+  supersats = g_strsplit(model->monty.supersaturations, "\n", INT_MAX);
   for (i = 0; *(supersats+i); ++i)
   {
     fprintf(fp, " -supersat %s\n", *(supersats +i));
@@ -551,7 +552,7 @@
   
   /* remove any whitespace, this also includes trailing \n characters */
   g_strstrip(model->monty.output_dirs);
-  gchar **out_dirs = g_strsplit(model->monty.output_dirs, "\n", INT_MAX);
+  out_dirs = g_strsplit(model->monty.output_dirs, "\n", INT_MAX);
   for (i = 0; *(out_dirs + i); ++i)
   {
     fprintf(fp, " -directory %s %s\n", *(hkls + i), *(out_dirs + i));
