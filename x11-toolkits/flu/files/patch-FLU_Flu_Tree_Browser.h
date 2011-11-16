--- FLU/Flu_Tree_Browser.h.orig	2004-11-05 18:03:20.000000000 +0100
+++ FLU/Flu_Tree_Browser.h	2011-11-16 10:36:16.000000000 +0100
@@ -218,10 +218,6 @@
   inline void color( Fl_Color c )
     { _box->color( c ); }
 
-  //! Set the background color of the browser. Default is FL_WHITE
-  inline void color( unsigned c )
-    { _box->color( (Fl_Color)c ); }
-
   //! Set the color, style, and width of the connector lines. Default is FL_DARK2, FL_DOT, 1
   inline void connector_style( Fl_Color color, int style, int width = 1 )
     { rdata.defLineColor = color; rdata.lineStyle = style; rdata.lineWidth = width; }
@@ -346,7 +342,7 @@
     { return rdata.insertionMode; }
 
   //! \return whether the point \c (x,y) is inside the entry area (not on the scrollbars)
-  bool Flu_Tree_Browser :: inside_entry_area( int x, int y );
+  bool inside_entry_area( int x, int y );
 
   //! Set the title of the Tree (also the label for the root entry)
   inline void label( const char *l )
@@ -436,23 +432,23 @@
 
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
@@ -494,10 +490,6 @@
   inline void selection_color( Fl_Color c )
     { rdata.defSelectionColor = c; }
 
-  //! Set the color to use when hilighting selected entries. Default is FL_SELECTION_COLOR
-  inline void selection_color( unsigned c )
-    { selection_color( (Fl_Color)c ); }
-
   //! Set how selection is affected when the mouse is dragged. This can be one of FLU_DRAG_IGNORE, FLU_DRAG_TO_SELECT, FLU_DRAG_TO_MOVE. Default is FLU_DRAG_TO_SELECT.
   inline void selection_drag_mode( int m )
     { rdata.selectionDragMode = m; }
@@ -1077,8 +1069,8 @@
 
       //! Remove the entry identified by path \b fullpath from this node
       /*! \return the unique id of the removed entry, or \c 0 if no matching entry was found */
-      inline unsigned int remove( const char *fullpath )
-	{ return( (unsigned int)modify( fullpath, REMOVE, tree->rdata ) ); }
+      inline unsigned long remove( const char *fullpath )
+	{ return( (unsigned long )modify( fullpath, REMOVE, tree->rdata ) ); }
 
       //! Remove the entry identified by unique id \b id from this node
       /*! \return the unique id of the removed entry, or \c 0 if no matching entry was found */
