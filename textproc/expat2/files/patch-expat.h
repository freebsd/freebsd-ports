--- lib/expat.h.orig	Sat Mar 17 12:57:01 2001
+++ lib/expat.h	Sat Mar 17 12:57:09 2001
@@ -703,7 +703,7 @@
 
 /* Return a string containing the version number of this expat */
 const XML_LChar XMLPARSEAPI *
-XML_ExpatVersion();
+XML_ExpatVersion(void);
 
 #ifdef __cplusplus
 }
