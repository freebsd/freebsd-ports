$FreeBSD$

--- builderFiles3.cpp.orig	Mon Jun 30 17:31:39 2003
+++ builderFiles3.cpp	Mon Jun 30 17:32:00 2003
@@ -73,6 +73,8 @@
       const XxFln f3n2 
    );
 
+  ~XxParseDiffError() throw() { }
+
 };
 
 //------------------------------------------------------------------------------
