--- multiFileData.h.orig	Sat May  9 02:47:03 1998
+++ multiFileData.h	Wed Mar 17 17:29:03 2004
@@ -53,7 +53,7 @@
 
   virtual void getNewFile();
   virtual void deleteFile();
-  virtual void fileChanged(const char*);
+  virtual void fileChanged(const QString&);
   virtual void insertCurrentFilename();
   virtual void insertNewFilename();
   virtual void apply();
