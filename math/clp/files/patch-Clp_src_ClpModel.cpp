--- Clp/src/ClpModel.cpp.orig	2018-04-16 06:43:28 UTC
+++ Clp/src/ClpModel.cpp
@@ -3845,7 +3845,7 @@ ClpModel::writeMps(const char *filename,
      writer.setMpsData(*(matrix_->getPackedMatrix()), COIN_DBL_MAX,
                        getColLower(), getColUpper(),
                        objective,
-                       reinterpret_cast<const char*> (NULL) /*integrality*/,
+                       nullptr /*integrality*/,
                        getRowLower(), getRowUpper(),
                        columnNames, rowNames);
      // Pass in array saying if each variable integer
