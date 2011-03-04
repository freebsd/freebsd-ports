--- src/core/filename_list.cpp	2010-11-12 00:31:17.000000000 +0100
+++ src/core/filename_list.cpp	2009-04-22 13:51:38.000000000 +0200
@@ -59,7 +59,7 @@
     // The vast majority of Unix systems want the sort function to have this
     // prototype, most likely so that it can be passed to qsort without any
     // changes:
-    return scandir(dir, list, 0, (int(*)(const void*,const void*))sort);
+    return scandir(dir, list, 0, (int(*)(const dirent **, const dirent **))sort);
 #else
     // This version is when we define our own scandir (WIN32 and perhaps
     // some Unix systems) and apparently on Irix:
