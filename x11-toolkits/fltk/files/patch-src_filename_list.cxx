--- src/filename_list.cxx.orig	2010-02-09 11:00:46.000000000 +0100
+++ src/filename_list.cxx	2010-02-09 11:35:23.000000000 +0100
@@ -54,7 +54,7 @@
                      Fl_File_Sort_F *sort) {
 #ifndef HAVE_SCANDIR
   int n = scandir(d, list, 0, sort);
-#elif defined(__hpux) || defined(__CYGWIN__)
+#elif defined(__hpux) || defined(__CYGWIN__) || defined(__FreeBSD__)
   // HP-UX, Cygwin define the comparison function like this:
   int n = scandir(d, list, 0, (int(*)(const dirent **, const dirent **))sort);
 #elif defined(__osf__)
