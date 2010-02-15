--- src/filename_list.cxx.orig	2006-06-09 18:16:34.000000000 +0200
+++ src/filename_list.cxx	2010-02-15 14:57:40.000000000 +0100
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
-#elif defined(__hpux) || defined(__CYGWIN__)
+#elif defined(__hpux) || defined(__CYGWIN__) || (defined(__FreeBSD__)  && __FreeBSD_version >= 900006)
   // HP-UX, Cygwin define the comparison function like this:
   int n = scandir(d, list, 0, (int(*)(const dirent **, const dirent **))sort);
 #elif defined(__osf__)
