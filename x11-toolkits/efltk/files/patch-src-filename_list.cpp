--- src/core/filename_list.cpp.orig	2009-04-22 20:51:38.000000000 +0900
+++ src/core/filename_list.cpp	2011-07-25 20:26:24.000000000 +0900
@@ -34,6 +34,7 @@
 
 #include <efltk/filename.h>
 #include <efltk/Fl_String.h>
+#include <sys/param.h>
 
 #if !HAVE_SCANDIR
   extern int fl_scandir(const char *dir, dirent ***namelist,
@@ -59,7 +60,11 @@
     // The vast majority of Unix systems want the sort function to have this
     // prototype, most likely so that it can be passed to qsort without any
     // changes:
+#if defined(__FreeBSD__) && (__FreeBSD_version >= 900006 || (__FreeBSD_version >= 800501 && __FreeBSD_version < 900000) || (__FreeBSD_version >= 730000 && __FreeBSD_version < 800000))
+    return scandir(dir, list, 0, (int(*)(const dirent **, const dirent **))sort);
+#else
     return scandir(dir, list, 0, (int(*)(const void*,const void*))sort);
+#endif
 #else
     // This version is when we define our own scandir (WIN32 and perhaps
     // some Unix systems) and apparently on Irix:
