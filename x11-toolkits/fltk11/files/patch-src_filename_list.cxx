--- src/filename_list.cxx.orig	2010-03-09 08:52:26.000000000 +0100
+++ src/filename_list.cxx	2010-03-09 08:54:53.000000000 +0100
@@ -30,7 +30,7 @@
 #include <FL/filename.H>
 #include "flstring.h"
 #include <stdlib.h>
-
+#include <sys/param.h>
 
 extern "C" {
 #ifndef HAVE_SCANDIR
@@ -54,7 +54,7 @@
                      Fl_File_Sort_F *sort) {
 #ifndef HAVE_SCANDIR
   int n = scandir(d, list, 0, sort);
-#elif defined(HAVE_SCANDIR_POSIX)
+#elif defined(HAVE_SCANDIR_POSIX) || (defined(__FreeBSD__)  && (__FreeBSD_version >= 900006 || (__FreeBSD_version >= 800501 && __FreeBSD_version < 900000) || (__FreeBSD_version >= 730000 && __FreeBSD_version < 800000)))
   // POSIX (2008) defines the comparison function like this:
   int n = scandir(d, list, 0, (int(*)(const dirent **, const dirent **))sort);
 #elif defined(__osf__)
