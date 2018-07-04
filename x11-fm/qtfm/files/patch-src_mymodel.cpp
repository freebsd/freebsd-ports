--- src/mymodel.cpp.orig	2018-07-04 09:21:07 UTC
+++ src/mymodel.cpp
@@ -166,7 +166,7 @@ QString myModel::filePath(const QModelIn
 
     if(item) return item->absoluteFilePath();
 
-    return false;
+    return QString();
 }
 
 //---------------------------------------------------------------------------------------
