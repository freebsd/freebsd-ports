------------------------------------------------------------------------
r10699 | greg.ercolano | 2015-04-13 16:55:27 +0000 (Mon, 13 Apr 2015) | 3 lines

Fix return value test, as pointed out by Albrecht.

--- src/Fl_Tree_Item.cxx.orig	2014-09-05 02:59:00 UTC
+++ src/Fl_Tree_Item.cxx
@@ -549,7 +549,7 @@ int Fl_Tree_Item::move(Fl_Tree_Item *ite
   } else {					// different parent?
     if ( to > to_parent->children() )		// try to prevent a reparent() error
       return -4;
-    if ( from_parent->deparent(from) < 0 )	// deparent self from current parent
+    if ( from_parent->deparent(from) == NULL )	// deparent self from current parent
       return -5;
     if ( to_parent->reparent(this, to) < 0 ) {	// reparent self to new parent at position 'to'
       to_parent->reparent(this, 0);		// failed? shouldn't happen, reparent at 0
