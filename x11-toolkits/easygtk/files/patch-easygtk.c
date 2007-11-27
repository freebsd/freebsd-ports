--- easygtk.c.orig	2007-11-25 22:00:42.000000000 +0100
+++ easygtk.c	2007-11-25 22:02:15.000000000 +0100
@@ -875,8 +875,8 @@
   strncpy(internal_result,out_string,1000);
   return g_strdup(internal_result); }
  strncpy(tmpstring,input_string,1024);
- (char *)tokens[i=0] = (char *)strtok(tmpstring, " ");
- while(((char *)tokens[++i] = (char *)strtok(NULL, " ")));
+ tokens[i=0] = (gchar *)strtok(tmpstring, " ");
+ while((tokens[++i] = (gchar *)strtok(NULL, " ")));
  tokens[i] = NULL;
  i++;
  if(i<starting_at)
@@ -899,8 +899,8 @@
  static gchar tmpstring[1024];
  gint i;
  strncpy(tmpstring,input_string,1024);
- (char *)tokens[i=0] = (char *)strtok(tmpstring, " ");
- while (((char *)tokens[++i] = (char *)strtok(NULL, " ")));
+ tokens[i=0] = (gchar *)strtok(tmpstring, " ");
+ while ((tokens[++i] = (gchar *)strtok(NULL, " ")));
  tokens[i] = NULL;
  return(g_strdup(tokens[word_number]));
 }
@@ -911,8 +911,8 @@
  static gchar tmpstring[1024];
  gint i;
  strncpy(tmpstring,input_string,1024);
- (char *)tokens[i=0] = (char *)strtok(tmpstring, delim);
- while (((char *)tokens[++i] = (char *)strtok(NULL, delim)));
+ tokens[i=0] = (gchar *)strtok(tmpstring, delim);
+ while ((tokens[++i] = (gchar *)strtok(NULL, delim)));
  tokens[i] = NULL;
  return(g_strdup(tokens[word_number]));
 }
