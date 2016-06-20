--- objects.c.orig	2016-06-20 16:04:03 UTC
+++ objects.c
@@ -99,7 +99,7 @@ panda_newobject (panda_pdf * doc, int ty
   created->children = (panda_child *) panda_xmalloc (sizeof (panda_child));
 
   ((panda_child *) created->children)->next = NULL;
-  (panda_child *) created->cachedLastChild = NULL;
+  created->cachedLastChild = NULL;
 
   // By default this object is not a pages object
   created->isPages = panda_false;
