--- pdixtract.c.orig	Thu Dec 14 00:18:17 2006
+++ pdixtract.c	Thu Dec 14 00:25:55 2006
@@ -79,6 +79,12 @@
         char name                       [1];
 };
 
+struct filedesc {
+  char *name;
+  size_t size; /* size in extents */
+  size_t extent;
+  int hits; /* flag for individual file selection */
+};
 
 char buffer[BUFFSIZE];
 struct filedesc files[MAX_FILES];
@@ -106,12 +112,6 @@
   exit(1);
 }
 
-struct filedesc {
-  char *name;
-  size_t size; /* size in extents */
-  size_t extent;
-  int hits; /* flag for individual file selection */
-};
 
 
 /* helper for qsort, compares extents of 2 filedescs */
