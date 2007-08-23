--- src/textcat.h.orig	Mon May 19 14:16:31 2003
+++ src/textcat.h	Thu Aug 23 22:47:07 2007
@@ -51,8 +51,17 @@
  * Returns: handle on success, NULL on error. (At the moment, the
  * only way errors can occur, is when the library cannot read the
  * conffile, or one of the fingerprint files listed in it.)
+ *
+ * Replace older function (and has exacly the same behaviour)
+ * see below
  */
 extern void *textcat_Init( const char *conffile );
+
+/**
+ * Originaly this function had only one parameter (conffile) it has been modified since OOo must be able to load alternativ DB
+ * Basicaly prefix is the directory path where fingerprints are stored
+ */
+extern void *special_textcat_Init( const char *conffile, const char *prefix );
 
 /**
  * textcat_Done() - Free up resources for handle
