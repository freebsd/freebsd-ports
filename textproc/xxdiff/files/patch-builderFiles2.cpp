$FreeBSD$

--- builderFiles2.cpp~	Tue Nov  6 07:30:32 2001
+++ builderFiles2.cpp	Mon Jun 30 17:40:21 2003
@@ -150,6 +150,8 @@
       const XxFln f2n2 
    );
 
+  ~XxParseDiffError() throw() { }
+
 };
 
 //------------------------------------------------------------------------------

