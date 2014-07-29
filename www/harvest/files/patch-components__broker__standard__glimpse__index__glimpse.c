--- components/broker/standard/glimpse/index/glimpse.c.orig	Wed May 30 19:09:39 2007
+++ components/broker/standard/glimpse/index/glimpse.c	Wed May 30 19:11:06 2007
@@ -18,12 +18,13 @@
 extern char  INDEX_DIR[MAX_LINE_LEN];
 extern struct stat istbuf;
 
-extern char	*TEMP_DIR; /* directory to store glimpse temporary files, usually /tmp unless -T is specified */
 #ifdef BUILDCAST
 /* TEMP_DIR is normally defined in ../main.c; if we're building
  * buildcast, that's not linked in, so we need to define one here. */
 /* char * TEMP_DIR = NULL; */
 static char * TEMP_DIR = "/tmp";
+#else
+extern char	*TEMP_DIR; /* directory to store glimpse temporary files, usually /tmp unless -T is specified */
 #endif /* BUILDCAST */
 extern int indexable_char[256];
 extern int GenerateHash;
