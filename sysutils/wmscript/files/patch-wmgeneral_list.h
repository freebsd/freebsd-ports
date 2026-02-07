--- wmgeneral/list.h.orig	1998-11-14 22:36:10 UTC
+++ wmgeneral/list.h
@@ -40,20 +40,20 @@ typedef struct LinkedList {
   struct LinkedList *tail;
 } LinkedList;
 
-INLINE LinkedList* list_cons(void* head, LinkedList* tail);
+extern INLINE LinkedList* list_cons(void* head, LinkedList* tail);
 
-INLINE int list_length(LinkedList* list);
+extern INLINE int list_length(LinkedList* list);
 
-INLINE void* list_nth(int index, LinkedList* list);
+extern INLINE void* list_nth(int index, LinkedList* list);
 
-INLINE void list_remove_head(LinkedList** list);
+extern INLINE void list_remove_head(LinkedList** list);
 
-INLINE LinkedList *list_remove_elem(LinkedList* list, void* elem);
+extern INLINE LinkedList *list_remove_elem(LinkedList* list, void* elem);
 
-INLINE void list_mapcar(LinkedList* list, void(*function)(void*));
+extern INLINE void list_mapcar(LinkedList* list, void(*function)(void*));
 
-INLINE LinkedList*list_find(LinkedList* list, void* elem);
+extern INLINE LinkedList*list_find(LinkedList* list, void* elem);
 
-INLINE void list_free(LinkedList* list);
+extern INLINE void list_free(LinkedList* list);
 
 #endif
