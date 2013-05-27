--- ./src/hashtable_itr.h.orig	2010-05-20 13:04:08.000000000 +0200
+++ ./src/hashtable_itr.h	2013-05-27 18:27:15.594067901 +0200
@@ -28,20 +28,14 @@
 /* hashtable_iterator_key
  * - return the value of the (key,value) pair at the current position */
 
-extern inline void *
-hashtable_iterator_key(struct hashtable_itr *i)
-{
-    return i->e->k;
-}
+void *
+hashtable_iterator_key(struct hashtable_itr *i);
 
 /*****************************************************************************/
 /* value - return the value of the (key,value) pair at the current position */
 
-extern inline void *
-hashtable_iterator_value(struct hashtable_itr *i)
-{
-    return i->e->v;
-}
+void *
+hashtable_iterator_value(struct hashtable_itr *i);
 
 /*****************************************************************************/
 /* advance - advance the iterator to the next element
