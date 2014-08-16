--- ./objects.c.orig	2004-04-13 02:46:24.000000000 +0200
+++ ./objects.c	2014-08-15 19:09:39.000000000 +0200
@@ -99,7 +99,7 @@
   created->children = (panda_child *) panda_xmalloc (sizeof (panda_child));
 
   ((panda_child *) created->children)->next = NULL;
-  (panda_child *) created->cachedLastChild = NULL;
+  created->cachedLastChild = NULL;
 
   // By default this object is not a pages object
   created->isPages = panda_false;
