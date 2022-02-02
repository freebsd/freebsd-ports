--- external/uthash/uthash.h.orig	2021-09-30 20:15:03 UTC
+++ external/uthash/uthash.h
@@ -226,17 +226,17 @@ do {                                                  
         _hd_hh_del = &((delptr)->hh);                                            \
         if ((delptr) == ELMT_FROM_HH((head)->hh.tbl,(head)->hh.tbl->tail)) {     \
             (head)->hh.tbl->tail =                                               \
-                (UT_hash_handle*)((ptrdiff_t)((delptr)->hh.prev) +               \
+                (UT_hash_handle*)((uintptr_t)((delptr)->hh.prev) +               \
                 (head)->hh.tbl->hho);                                            \
         }                                                                        \
         if ((delptr)->hh.prev) {                                                 \
-            ((UT_hash_handle*)((ptrdiff_t)((delptr)->hh.prev) +                  \
+            ((UT_hash_handle*)((uintptr_t)((delptr)->hh.prev) +                  \
                     (head)->hh.tbl->hho))->next = (delptr)->hh.next;             \
         } else {                                                                 \
             DECLTYPE_ASSIGN(head,(delptr)->hh.next);                             \
         }                                                                        \
         if (_hd_hh_del->next) {                                                  \
-            ((UT_hash_handle*)((ptrdiff_t)_hd_hh_del->next +                     \
+            ((UT_hash_handle*)((uintptr_t)_hd_hh_del->next +                     \
                     (head)->hh.tbl->hho))->prev =                                \
                     _hd_hh_del->prev;                                            \
         }                                                                        \
