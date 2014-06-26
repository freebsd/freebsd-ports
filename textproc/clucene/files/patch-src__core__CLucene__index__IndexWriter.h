--- src/core/CLucene/index/IndexWriter.h.orig	2011-03-16 20:21:07.000000000 -0400
+++ src/core/CLucene/index/IndexWriter.h	2014-06-24 18:17:57.000000000 -0400
@@ -384,14 +384,6 @@
    */
   static const int32_t DEFAULT_MAX_MERGE_DOCS;
 
-  /**
-   * Absolute hard maximum length for a term.  If a term
-   * arrives from the analyzer longer than this length, it
-   * is skipped and a message is printed to infoStream, if
-   * set (see {@link #setInfoStream}).
-   */
-  static const int32_t MAX_TERM_LENGTH;
-
 
   /* Determines how often segment indices are merged by addDocument().  With
    *  smaller values, less RAM is used while indexing, and searches on
