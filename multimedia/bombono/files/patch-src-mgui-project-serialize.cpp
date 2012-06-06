--- src/mgui/project/serialize.cpp.orig	2012-06-05 18:34:29.000000000 +0200
+++ src/mgui/project/serialize.cpp	2012-06-05 18:35:16.000000000 +0200
@@ -71,7 +71,7 @@
         return "untitled.bmd";
 
     fs::path full_path(db.GetProjectFName());
-    std::string res_str = full_path.leaf();
+    std::string res_str = full_path.filename().string();
     if( with_path_breakdown )
         res_str += " (" + full_path.branch_path().string() + ")";
     return res_str;
