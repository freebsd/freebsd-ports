--- src/gtkrc-util.c.orig	Thu Sep  2 00:03:32 2004
+++ src/gtkrc-util.c	Thu Sep  2 00:05:38 2004
@@ -128,10 +128,11 @@
 int get_scrollbar_slider_length (char *scrollbar_fname)
 {
   GString * temp_string;
-  temp_string = g_string_new(NULL);
   int retval = 15;
+  FILE *fp;
+  temp_string = g_string_new(NULL);
 
-  FILE *fp = fopen (scrollbar_fname, "r");
+  fp = fopen (scrollbar_fname, "r");
   if (fp == NULL)
     {
       return retval;
@@ -167,10 +168,11 @@
 
 gboolean get_scrollbar_has_backward_stepper (char *scrollbar_fname){
   GString * temp_string;
-  temp_string = g_string_new(NULL);
   gboolean retval = TRUE;
+  FILE *fp;
+  temp_string = g_string_new(NULL);
 
-  FILE *fp = fopen (scrollbar_fname, "r");
+  fp = fopen (scrollbar_fname, "r");
   if (fp == NULL)
     {
       return retval;
@@ -211,10 +213,11 @@
 gboolean get_scrollbar_has_secondary_backward_stepper (char *scrollbar_fname)
 {
   GString * temp_string;
-  temp_string = g_string_new(NULL);
   gboolean retval = FALSE;
+  FILE *fp;
+  temp_string = g_string_new(NULL);
 
-  FILE *fp = fopen (scrollbar_fname, "r");
+  fp = fopen (scrollbar_fname, "r");
   if (fp == NULL)
     {
       return retval;
@@ -301,10 +304,11 @@
 gboolean get_enable_colors (char *gtkrc_fname)
 {
   GString * temp_string;
-  temp_string = g_string_new(NULL);
   gboolean retval = FALSE;
+  FILE *fp;
+  temp_string = g_string_new(NULL);
 
-  FILE *fp = fopen (gtkrc_fname, "r");
+  fp = fopen (gtkrc_fname, "r");
   if (fp == NULL)
     {
       return FALSE;
@@ -342,10 +346,11 @@
 char *get_widget_color (char *widget_fname, char *color_name)
 {
   GString * temp_string;
-  temp_string = g_string_new(NULL);
   char retval[7] = "#ffffff";
+  FILE *fp;
+  temp_string = g_string_new(NULL);
 
-  FILE *fp = fopen (widget_fname, "r");
+  fp = fopen (widget_fname, "r");
   if (fp == NULL)
     {
       return g_string_new(retval)->str;
@@ -356,13 +361,14 @@
       c = getc(fp);
       while(c!=EOF)
 	{
+	  GString *match_string;
 	  while(c!=EOF && c!='\n')
 	    {
 	      temp_string = g_string_append_c(temp_string, c);
 	      c = getc(fp);
 	    }
 	  temp_string = g_string_new(g_strstrip(temp_string->str));
-	  GString *match_string = g_string_new(color_name);
+	  match_string = g_string_new(color_name);
 	  match_string = g_string_append(match_string, " = *");
 
 	  if (g_pattern_match_simple(match_string->str, temp_string->str))
