--- modules/matio/src/cpp/GetSparseVariable.cpp.orig	2026-05-19 09:32:07 UTC
+++ modules/matio/src/cpp/GetSparseVariable.cpp
@@ -64,7 +64,7 @@ matvar_t* GetSparseMatVar(types::Sparse* pSparse, cons
     int* itemsRow = new int[pSparse->getRows()];
     pSparse->getNbItemByRow(itemsRow);
 
-#if MATIO_RELEASE_LEVEL < 18
+#if MATIO_VERSION < 1518
     mat_int32_t* colIndexes = (mat_int32_t*)MALLOC(sizeof(mat_int32_t) *  (pSparse->getRows() + 1));
 #else
     mat_uint32_t* colIndexes = (mat_uint32_t*)MALLOC(sizeof(mat_uint32_t) *  (pSparse->getRows() + 1));
@@ -85,7 +85,7 @@ matvar_t* GetSparseMatVar(types::Sparse* pSparse, cons
         colIndexes[K + 1] = colIndexes[K] + itemsRow[K];
     }
 
-#if MATIO_RELEASE_LEVEL < 18
+#if MATIO_VERSION < 1518
     mat_int32_t* rowIndexes = (mat_int32_t*)MALLOC(sizeof(mat_int32_t) *  nonZeros);
 #else
     mat_uint32_t* rowIndexes = (mat_uint32_t*)MALLOC(sizeof(mat_uint32_t) *  nonZeros);
