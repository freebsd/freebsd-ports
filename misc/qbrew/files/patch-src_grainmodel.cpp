QAbstractItemModel API change

--- src/grainmodel.cpp.orig	2018-11-26 11:49:13 UTC
+++ src/grainmodel.cpp
@@ -38,7 +38,8 @@ GrainModel::~GrainModel(){}
 
 void GrainModel::flush()
 {
-    reset();
+    beginResetModel();
+    endResetModel();
 }
 
 //////////////////////////////////////////////////////////////////////////////
