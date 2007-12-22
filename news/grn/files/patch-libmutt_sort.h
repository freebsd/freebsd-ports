--- libmutt/sort.h.orig	2007-12-20 19:32:43.000000000 +0100
+++ libmutt/sort.h	2007-12-20 19:32:55.000000000 +0100
@@ -45,4 +45,4 @@
 WHERE short SortAux INITVAL (SORT_DATE); /* auxiallary sorting method */
 WHERE short SortAlias INITVAL (SORT_ALIAS);
 
-extern const struct mapping_t SortMethods[];
+extern const struct mapping_t *SortMethods;
