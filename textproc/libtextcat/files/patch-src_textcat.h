--- ./src/textcat.h.orig	2003-05-19 14:16:31.000000000 +0200
+++ ./src/textcat.h	2010-12-21 16:18:55.000000000 +0100
@@ -39,6 +39,9 @@
 
 #define _TEXTCAT_RESULT_UNKOWN        "UNKNOWN"
 #define _TEXTCAT_RESULT_SHORT         "SHORT"
+#ifdef __cplusplus
+extern "C" {
+#endif
 
 
 /**
@@ -51,10 +54,19 @@
  * Returns: handle on success, NULL on error. (At the moment, the
  * only way errors can occur, is when the library cannot read the
  * conffile, or one of the fingerprint files listed in it.)
+ *
+ * Replace older function (and has exacly the same behaviour)
+ * see below
  */
 extern void *textcat_Init( const char *conffile );
 
 /**
+ * Originaly this function had only one parameter (conffile) it has been modified since OOo must be able to load alternativ DB
+ * Basicaly prefix is the directory path where fingerprints are stored
+ */
+extern void *special_textcat_Init( const char *conffile, const char *prefix );
+
+/**
  * textcat_Done() - Free up resources for handle
  */
 extern void textcat_Done( void *handle );
@@ -77,4 +89,8 @@
  * textcat_Version() - Returns a string describing the version of this classifier.
  */
 extern char *textcat_Version();
+
+#ifdef __cplusplus
+}
+#endif
 #endif
