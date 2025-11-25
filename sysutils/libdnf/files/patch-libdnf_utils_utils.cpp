--- libdnf/utils/utils.cpp.orig	2025-11-25 05:02:56 UTC
+++ libdnf/utils/utils.cpp
@@ -308,10 +308,10 @@ std::vector<std::string> createSortedFileList(
             if (path[strlen(path)-1] == '/') {
                 continue;
             }
-            auto * path_fname = basename(path);
+            auto * path_fname = g_basename(path);
             bool found{false};
             for (const auto & path_in_list : paths) {
-                if (strcmp(path_fname, basename(path_in_list.c_str())) == 0) {
+                if (strcmp(path_fname, g_basename(path_in_list.c_str())) == 0) {
                     found = true;
                     break;
                 }
@@ -325,7 +325,7 @@ std::vector<std::string> createSortedFileList(
 
     // sort all drop-in configuration files alphabetically by their names
     std::sort(paths.begin(), paths.end(), [](const std::string & p1, const std::string & p2) {
-        return strcmp(basename(p1.c_str()), basename(p2.c_str())) < 0;
+        return strcmp(g_basename(p1.c_str()), g_basename(p2.c_str())) < 0;
     });
 
     return paths;
