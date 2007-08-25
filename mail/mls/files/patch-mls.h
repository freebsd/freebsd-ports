--- mls.h.orig	2007-08-26 03:26:30.000000000 +0800
+++ mls.h	2007-08-26 03:27:11.000000000 +0800
@@ -75,6 +75,9 @@
 #define EXIT_NOMEM  4
 #define EXIT_REGEX  5
 
+// because we must specify it when 2dimensional array is passed to function
+#define SNUMB_LEN   4
+
 /* *** structures for BEST messages *** */
 typedef struct bestQUOTE* nQptr;
 struct bestQUOTE {
