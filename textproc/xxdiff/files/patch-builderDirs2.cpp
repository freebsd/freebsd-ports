$FreeBSD$

--- builderDirs2.cpp.orig	Mon Jun 30 17:32:25 2003
+++ builderDirs2.cpp	Mon Jun 30 17:32:46 2003
@@ -94,6 +94,8 @@
       const char* buf
    );
 
+  ~XxParseDiffError() throw() { }
+
 };
 
 /*==============================================================================
