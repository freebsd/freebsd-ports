--- phpmrss/php.c.orig	2007-12-20 14:28:23.072883854 +0800
+++ phpmrss/php.c	2007-12-20 14:28:48.234880979 +0800
@@ -450,16 +450,6 @@
   MAKE_STD_ZVAL(item);
   if (array_init(item) == FAILURE) {
      FREE_ZVAL(item);
-
-    add_index_zval(category, i++, category_zval);
-    c=c->next;
-  }
-
-  add_assoc_zval(return_value,"category", category);
-
-  MAKE_STD_ZVAL(item);
-  if (array_init(item) == FAILURE) {
-     FREE_ZVAL(item);
      return;
   }
 
