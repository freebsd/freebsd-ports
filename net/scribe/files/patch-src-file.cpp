--- src/file.cpp.orig	2012-06-28 12:42:20.000000000 +0800
+++ src/file.cpp	2012-06-28 12:42:30.000000000 +0800
@@ -245,7 +245,7 @@
       boost::filesystem::directory_iterator dir_iter(path), end_iter;
 
       for ( ; dir_iter != end_iter; ++dir_iter) {
-        _return.push_back(dir_iter->filename());
+        _return.push_back(dir_iter->path().filename().string());
       }
     }
   } catch (const std::exception& e) {
