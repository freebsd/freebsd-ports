--- objects.c.orig	Tue Apr 13 09:46:24 2004
+++ objects.c	Wed Jun 27 23:25:53 2007
@@ -99,7 +99,7 @@
   created->children = (panda_child *) panda_xmalloc (sizeof (panda_child));
 
   ((panda_child *) created->children)->next = NULL;
-  (panda_child *) created->cachedLastChild = NULL;
+  created->cachedLastChild = NULL;
 
   // By default this object is not a pages object
   created->isPages = panda_false;
