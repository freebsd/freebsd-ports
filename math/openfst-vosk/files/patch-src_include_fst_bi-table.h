--- src/include/fst/bi-table.h.orig	2021-02-07 08:38:45 UTC
+++ src/include/fst/bi-table.h
@@ -327,7 +327,7 @@ class VectorHashBiTable {
   }
 
   VectorHashBiTable(const VectorHashBiTable<I, T, S, FP, H, HS> &table)
-      : selector_(table.s_),
+      : selector_(table.selector_),
         fp_(table.fp_),
         h_(table.h_),
         id2entry_(table.id2entry_),
