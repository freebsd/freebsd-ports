--- ./index/glimpse.c.orig	1999-03-02 07:37:55.000000000 +0000
+++ ./index/glimpse.c	2014-01-27 21:40:18.000000000 +0000
@@ -23,7 +23,7 @@
 /* TEMP_DIR is normally defined in ../main.c; if we're building
  * buildcast, that's not linked in, so we need to define one here. */
 /* char * TEMP_DIR = NULL; */
-static char * TEMP_DIR = "/tmp";
+char * TEMP_DIR = "/tmp";
 #endif /* BUILDCAST */
 extern int indexable_char[256];
 extern int GenerateHash;
