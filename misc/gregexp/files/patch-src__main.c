--- src/main.c.orig	Wed Mar 10 17:35:40 2004
+++ src/main.c	Thu Jul  1 21:03:44 2004
@@ -107,16 +107,20 @@
 
 void set_escaped ( gchar * expression, unsigned int levels )
 {
+  unsigned int num;
+  gchar * escaped;
+  unsigned int x; // temp var
+  unsigned int i, j;
+
   if ( !expression )
     return;
 
-  unsigned int num = (1<<levels)-1;
-  gchar * escaped = g_malloc ( (strlen ( expression ) * (num+1) )+1 ); // worst case if each character would be escaped
+  num = (1<<levels)-1;
+  escaped = g_malloc ( (strlen ( expression ) * (num+1) )+1 ); // worst case if each character would be escaped
   escaped[0] = 0;
 
-  unsigned int x; // temp var
-  unsigned int i = 0;
-  unsigned int j = 0;
+  i = 0;
+  j = 0;
   while ( expression[i] )
     {
       switch ( expression[i] )
@@ -144,10 +148,12 @@
 
 void clear_result ()
 {
+  ResultItem * result;
+
   if ( !lastResult )
     return;
 
-  ResultItem * result = lastResult;
+  result = lastResult;
   while ( result->position >= 0 )
     {
       if ( result->value )
@@ -202,14 +208,16 @@
 ResultItem * transform ( int * ovector, unsigned int matches, const gchar * data )
 {
   ResultItem * resultItems;
+  int parent;
+  GTrashStack * stack;
+  unsigned int o;
 
   resultItems = g_malloc ( sizeof(ResultItem)*(matches+1) );
 
-  int parent = 0;
+  parent = 0;
 
-  GTrashStack * stack = NULL;
+  stack = NULL;
 
-  unsigned int o;
   for ( o = 0; o<matches; o++ )
     {
       int offset = ovector[o*2];
@@ -268,17 +276,18 @@
 {
   GtkTextIter iter;
   GtkTextBuffer * buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(resultEntry) );
+  gchar * result;
+  int o, j, i, x;
 
   gtk_text_buffer_set_text ( buffer, "", -1 );
 
   gtk_text_buffer_get_iter_at_offset (buffer, &iter, 0);
 
-  gchar * result = g_malloc ( (strlen ( data ) + 128 ) * 2 );
+  result = g_malloc ( (strlen ( data ) + 128 ) * 2 );
 
-  int o;
-  int j = 0;
-  int i = 0;
-  int x = 0;
+  j = 0;
+  i = 0;
+  x = 0;
   while ( data[i] )
     {
       for ( o = 0; o<matches; o++ )
@@ -362,6 +371,8 @@
 
   int flags = PCRE_UTF8;
 
+  ResultItem * resultItems;
+
   if ( opt_multiline() )
     flags |= PCRE_MULTILINE;
 
@@ -403,7 +414,6 @@
 
   // Fill result tree
 
-  ResultItem * resultItems;
   resultItems = transform ( ovector, rc, data );
   update_model ( resultItems, resultTree );
 
@@ -441,14 +451,14 @@
   GtkTreeSelection * sel;
   GtkTreeModel * model;
   GtkTreeIter iter;
+  gint position;
+
   sel = gtk_tree_view_get_selection ( GTK_TREE_VIEW(resultTree) );
 
   if ( !gtk_tree_selection_get_selected ( sel, &model, &iter ) )
     {
       return;
     }
-
-  gint position;
 
   gtk_tree_model_get ( model, &iter, POSITION_COLUMN, &position, -1 );
 
