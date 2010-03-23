--- FLU/Flu_Tree_Browser.h.orig	2010-01-15 11:50:51.000000000 +0100
+++ FLU/Flu_Tree_Browser.h	2010-01-15 11:55:24.000000000 +0100
@@ -346,7 +346,7 @@
     { return rdata.insertionMode; }
 
   //! \return whether the point \c (x,y) is inside the entry area (not on the scrollbars)
-  bool Flu_Tree_Browser :: inside_entry_area( int x, int y );
+  bool inside_entry_area( int x, int y );
 
   //! Set the title of the Tree (also the label for the root entry)
   inline void label( const char *l )
@@ -436,23 +436,23 @@
 
   //! Remove the entry identified by path \b fullpath from the tree
   /*! \return the unique id of the removed entry, or \c 0 if no matching entry was found */
-  unsigned int remove( const char *fullpath );
+  unsigned long remove( const char *fullpath );
 
   //! Remove entry \b name in path \b path from the tree
   /*! \return the unique id of the removed entry, or \c 0 if no matching entry was found */
-  unsigned int remove( const char *path, const char *name );
+  unsigned long remove( const char *path, const char *name );
 
   //! Remove the entry identified by unique id \b id from the tree
   /*! \return the unique id of the removed entry, or \c 0 if no matching entry was found */
-  unsigned int remove( unsigned int id );
+  unsigned long remove( unsigned int id );
 
   //! Remove the entry containing the widget \b w from the tree. Note that the widget is automatically destroyed
   /*! \return the unique id of the removed entry, or \c 0 if no matching entry was found */
-  unsigned int remove( Fl_Widget *w );
+  unsigned long remove( Fl_Widget *w );
 
   //! Remove Node \b n from the tree
   /*! \return the id of \b n on successful removal, or \c 0 if \b n is not in the tree */
-  inline unsigned int remove( Node* n )
+  inline unsigned long remove( Node* n )
     { if( !n ) return 0; else return remove( n->id() ); }
 
   //! Override of Fl_Widget::resize
@@ -1077,8 +1077,8 @@
 
       //! Remove the entry identified by path \b fullpath from this node
       /*! \return the unique id of the removed entry, or \c 0 if no matching entry was found */
-      inline unsigned int remove( const char *fullpath )
-	{ return( (unsigned int)modify( fullpath, REMOVE, tree->rdata ) ); }
+      inline unsigned long remove( const char *fullpath )
+	{ return( (unsigned long )modify( fullpath, REMOVE, tree->rdata ) ); }
 
       //! Remove the entry identified by unique id \b id from this node
       /*! \return the unique id of the removed entry, or \c 0 if no matching entry was found */
