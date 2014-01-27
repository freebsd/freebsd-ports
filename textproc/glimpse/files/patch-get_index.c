--- ./get_index.c.orig	1998-04-07 16:17:54.000000000 +0000
+++ ./get_index.c	2014-01-27 21:40:18.000000000 +0000
@@ -52,7 +52,7 @@
 }
 
 /* Unions offset lists list2 with list1 sorted in increasing order (deletes elements from list2) => changes both list1 and list2: f += #elems added */
-sorted_union(list1, list2, f, pf, cf)
+void sorted_union(list1, list2, f, pf, cf)
 	struct offsets **list1, **list2;
 	int	*f, pf, cf;
 {
@@ -114,7 +114,7 @@
 }
 
 /* Intersects offset lists list2 with list1 sorted in increasing order (deletes elements from list2) => changes both list1 and list2 */
-sorted_intersection(filenum, list1, list2, f)
+void sorted_intersection(filenum, list1, list2, f)
 	struct offsets **list1, **list2;
 	int	*f;
 {
