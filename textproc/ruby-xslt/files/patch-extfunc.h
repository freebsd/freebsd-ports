--- extfunc.h.orig	Mon Mar 28 21:48:01 2005
+++ extfunc.h	Tue Aug  9 17:04:58 2005
@@ -21,7 +21,7 @@
 /* this stores function names and the ids of the objects they belong to, indexed by name and namespace */
 static xmlHashTablePtr pExtFunctionsHashTable = NULL;
 
-void deallocateCallback( void *, xmlChar * ATTRIBUTE_UNUSED );
+void deallocateCallback( void *payload, xmlChar *name ATTRIBUTE_UNUSED );
 VALUE xpathObj2value( xmlXPathObjectPtr, xmlDocPtr );
 xmlXPathObjectPtr value2xpathObj( VALUE );
 void xmlXPathFuncCallback( xmlXPathParserContextPtr, int );
