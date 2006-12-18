--- htsearch/Collection.h.orig	Fri May 28 06:15:24 2004
+++ htsearch/Collection.h	Mon Dec 18 00:17:56 2006
@@ -36,9 +36,9 @@
                const char *docExcerpt);
     ~Collection();
 
-    void Collection::Open();
+    void Open();
 
-    void Collection::Close(); 
+    void Close(); 
 
     char *getWordFile() { return wordFile.get(); }
     DocumentRef         *getDocumentRef(int id);
