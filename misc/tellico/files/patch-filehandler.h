--- src/filehandler.h.orig	Tue Feb 24 01:11:58 2004
+++ src/filehandler.h	Tue Feb 24 01:08:37 2004
@@ -39,6 +39,7 @@
 
 friend class MainWindow;
 friend const Data::Image& addImage(const KURL& url);
+class FileRef;
 friend class FileRef;
 
 public:
