--- src/list.h	2018-01-04 20:59:38 UTC
+++ src/list.h
@@ -23,7 +23,7 @@ static inline LIST* last_list_elem(LIST 
 
 static inline void add_to_list(LIST *list, LIST *elem){
     /* Yes, i want SIGSEGV for debug */
-    if ((elem->next != NULL) || (elem->prev != NULL)) *((char*)NULL) = '\0';
+    if ((elem->next != NULL) || (elem->prev != NULL)) __builtin_trap();
 
     elem->next = list->next;
     elem->prev = list;
@@ -33,7 +33,7 @@ static inline void add_to_list(LIST *lis
 
 static inline void add_to_list_back(LIST *list, LIST *elem){
     /* Yes, i want SIGSEGV for debug */
-    if ((elem->next != NULL) || (elem->prev != NULL)) *((char*)NULL) = '\0';
+    if ((elem->next != NULL) || (elem->prev != NULL)) __builtin_trap();
 
     elem->next = list;
     elem->prev = list->prev;
@@ -45,7 +45,7 @@ static inline void insert_to_list_after(
     (void)list;
 
     /* Yes, i want SIGSEGV for debug */
-    if ((new_elem->next != NULL) || (new_elem->prev != NULL)) *((char*)NULL) = '\0';
+    if ((new_elem->next != NULL) || (new_elem->prev != NULL)) __builtin_trap();
 
     new_elem->next = elem->next;
     new_elem->prev = elem;
@@ -57,7 +57,7 @@ static inline void insert_to_list_before
     (void)list;
 
     /* Yes, i want SIGSEGV for debug */
-    if ((new_elem->next != NULL) || (new_elem->prev != NULL)) *((char*)NULL) = '\0';
+    if ((new_elem->next != NULL) || (new_elem->prev != NULL)) __builtin_trap();
 
     new_elem->next = elem;
     new_elem->prev = elem->prev;
