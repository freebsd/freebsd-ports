--- modules/matio/src/cpp/GetSparseVariable.cpp.orig	2020-02-25 10:00:03 UTC
+++ modules/matio/src/cpp/GetSparseVariable.cpp
@@ -65,7 +65,7 @@ matvar_t* GetSparseMatVar(types::Sparse* pSparse, cons
     int* itemsRow = new int[pSparse->getRows()];
     pSparse->getNbItemByRow(itemsRow);
 
-    int* colIndexes = (int*)MALLOC(sizeof(int) *  (pSparse->getRows() + 1));
+    mat_uint32_t* colIndexes = (mat_uint32_t*)MALLOC(sizeof(mat_uint32_t) *  (pSparse->getRows() + 1));
     if (colIndexes == NULL)
     {
         FREE(sparseData);
@@ -82,7 +82,7 @@ matvar_t* GetSparseMatVar(types::Sparse* pSparse, cons
         colIndexes[K + 1] = colIndexes[K] + itemsRow[K];
     }
 
-    int* rowIndexes = (int*)MALLOC(sizeof(int) *  nonZeros);
+    mat_uint32_t* rowIndexes = (mat_uint32_t*)MALLOC(sizeof(mat_uint32_t) *  nonZeros);
     if (rowIndexes == NULL)
     {
         FREE(sparseData);
