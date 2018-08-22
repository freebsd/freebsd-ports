--- lib/linklist.h.orig	2018-07-12 06:56:52 UTC
+++ lib/linklist.h
@@ -84,9 +84,6 @@ extern void *listnode_head(struct list *);
  * and remove list_delete_original and the list_delete #define
  * Additionally remove list_free entirely
  */
-#if CONFDATE > 20181001
-CPP_NOTICE("list_delete without double pointer is deprecated, please fixup")
-#endif
 extern void list_delete_and_null(struct list **);
 extern void list_delete_original(struct list *);
 #define list_delete(X) list_delete_original((X))			\
