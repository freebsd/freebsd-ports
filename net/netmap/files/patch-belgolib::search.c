--- belgolib/search.c.orig	Sun Dec 15 14:54:27 2002
+++ belgolib/search.c	Sun Dec 15 14:54:27 2002
@@ -5,7 +5,7 @@
 // SearchPath members
 
 
-void SearchPath::add_dir(const list<string>& dlist, int depth = 0) 
+void SearchPath::add_dir(const list<string>& dlist, int depth) 
 {
     for(CSiter diter = dlist.begin(); diter != dlist.end(); diter++) 
 	add_dir( *diter, depth);    
