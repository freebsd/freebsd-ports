ClpModel.cpp:3848:24: error: reinterpret_cast from 'nullptr_t' to 'const char *' is not allowed
                       reinterpret_cast<const char*> (NULL) /*integrality*/,
                       ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

--- src/coin/Clp/ClpModel.cpp.orig	2015-05-29 15:36:41 UTC
+++ src/coin/Clp/ClpModel.cpp
@@ -3619,7 +3619,7 @@ ClpModel::writeMps(const char *filename,
      writer.setMpsData(*(matrix_->getPackedMatrix()), COIN_DBL_MAX,
                        getColLower(), getColUpper(),
                        objective,
-                       reinterpret_cast<const char*> (NULL) /*integrality*/,
+                       static_cast<const char*> (NULL) /*integrality*/,
                        getRowLower(), getRowUpper(),
                        columnNames, rowNames);
      // Pass in array saying if each variable integer
