--- dependencies/osi_clp/Clp/src/ClpModel.cpp.orig	2018-04-10 05:06:37 UTC
+++ dependencies/osi_clp/Clp/src/ClpModel.cpp
@@ -3845,7 +3845,7 @@ ClpModel::writeMps(const char *filename,
      writer.setMpsData(*(matrix_->getPackedMatrix()), COIN_DBL_MAX,
                        getColLower(), getColUpper(),
                        objective,
-                       reinterpret_cast<const char*> (NULL) /*integrality*/,
+                       static_cast<const char*> (NULL) /*integrality*/,
                        getRowLower(), getRowUpper(),
                        columnNames, rowNames);
      // Pass in array saying if each variable integer
