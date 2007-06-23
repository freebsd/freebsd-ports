--- ./index/glimpse.c.orig	2007-06-21 22:24:44.000000000 -0500
+++ ./index/glimpse.c	2007-06-21 22:25:15.000000000 -0500
@@ -23,7 +23,7 @@
 /* TEMP_DIR is normally defined in ../main.c; if we're building
  * buildcast, that's not linked in, so we need to define one here. */
 /* char * TEMP_DIR = NULL; */
-static char * TEMP_DIR = "/tmp";
+char * TEMP_DIR = "/tmp";
 #endif /* BUILDCAST */
 extern int indexable_char[256];
 extern int GenerateHash;



