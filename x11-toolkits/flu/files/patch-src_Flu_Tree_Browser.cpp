--- src/Flu_Tree_Browser.cpp.orig	2010-01-15 11:54:00.000000000 +0100
+++ src/Flu_Tree_Browser.cpp	2010-01-15 11:57:06.000000000 +0100
@@ -2981,12 +2981,12 @@
   return add( path, p.c_str(), w, showLabel );
 }
 
-unsigned int Flu_Tree_Browser :: remove( const char *fullpath )
+unsigned long Flu_Tree_Browser :: remove( const char *fullpath )
 {
-  return( (unsigned int)root.modify( fullpath, Node::REMOVE, rdata ) );
+  return( (unsigned long)root.modify( fullpath, Node::REMOVE, rdata ) );
 }
 
-unsigned int Flu_Tree_Browser :: remove( const char *path, const char *text )
+unsigned long Flu_Tree_Browser :: remove( const char *path, const char *text )
 {
   // if the path does not end in '/', add it
   FluSimpleString s = path;
@@ -2996,7 +2996,7 @@
   return remove( s.c_str() );
 }
 
-unsigned int Flu_Tree_Browser :: remove( unsigned int id )
+unsigned long Flu_Tree_Browser :: remove( unsigned int id )
 {
   return root.remove( id );
 }
@@ -3028,7 +3028,7 @@
   return 0;
 }
 
-unsigned int Flu_Tree_Browser :: remove( Fl_Widget *w )
+unsigned long Flu_Tree_Browser :: remove( Fl_Widget *w )
 {
   return root.remove( w );
 }
