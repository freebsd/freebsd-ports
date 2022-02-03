--- external/libucl/uthash/uthash.h.orig	2021-11-12 08:57:25 UTC
+++ external/libucl/uthash/uthash.h
@@ -227,17 +227,17 @@ do {                                                  
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
