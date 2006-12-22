--- src/wsdlparser/WsdlParser.h.orig	Fri Dec 22 20:52:12 2006
+++ src/wsdlparser/WsdlParser.h	Fri Dec 22 20:52:33 2006
@@ -228,7 +228,7 @@
    */
 
   void
-    WsdlParser::getSchemaParsers(std::vector<SchemaParser* >::iterator & from,
+    getSchemaParsers(std::vector<SchemaParser* >::iterator & from,
 				 std::vector<SchemaParser* >::iterator & to) ;
   
   /**
