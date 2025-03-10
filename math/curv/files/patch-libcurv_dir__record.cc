--- libcurv/dir_record.cc.orig	2025-01-11 10:02:34 UTC
+++ libcurv/dir_record.cc
@@ -39,7 +39,7 @@ Dir_Record::Dir_Record(Filesystem::path dir, const Con
     fs::directory_iterator end;
     for (; i != end; ++i) {
         auto path = i->path();
-        auto name = path.leaf().string();
+        auto name = path.filename().string();
         auto cname = name.c_str();
         if (cname[0] == '.') continue;
         
