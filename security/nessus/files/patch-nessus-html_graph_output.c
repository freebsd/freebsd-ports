--- nessus/html_graph_output.c.old	Thu Jan 17 18:44:40 2002
+++ nessus/html_graph_output.c	Thu Jan 17 18:47:20 2002
@@ -65,8 +65,9 @@
 #include "globals.h"
 #include "nsr_output.h"
 
-
+#ifndef __FreeBSD__
 static char* strcasestr(char*, char *);
+#endif 
 static void insert_img(FILE *, char*);
 
 
@@ -90,7 +91,8 @@
 /*
  * Handy functions
  */
- 
+
+#ifndef __FreeBSD__ 
 static char * 
 strcasestr(char * haystack, char * needle)
 {
@@ -109,6 +111,7 @@
  }
  return NULL;
 }
+#endif
 
 static void
 insert_img(f, name)
