ClpModel.cpp:3848:24: error: reinterpret_cast from 'nullptr_t' to 'const char *' is not allowed
                       reinterpret_cast<const char*> (NULL) /*integrality*/,
                       ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

--- Clp/src/ClpModel.cpp.orig	2015-03-19 08:09:18 UTC
+++ Clp/src/ClpModel.cpp
@@ -3845,7 +3845,7 @@ ClpModel::writeMps(const char *filename,
      writer.setMpsData(*(matrix_->getPackedMatrix()), COIN_DBL_MAX,
                        getColLower(), getColUpper(),
                        objective,
-                       reinterpret_cast<const char*> (NULL) /*integrality*/,
+                       static_cast<const char*> (NULL) /*integrality*/,
                        getRowLower(), getRowUpper(),
                        columnNames, rowNames);
      // Pass in array saying if each variable integer
