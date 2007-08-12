--- src/wsdlparser/WsdlInvoker.h.orig	2007-08-12 13:34:25.000000000 +0200
+++ src/wsdlparser/WsdlInvoker.h	2007-08-12 13:34:42.000000000 +0200
@@ -204,7 +204,7 @@
   // set credentials for the service
   void setCredentials(const std::string & user, const std::string & pass);
   //ouput the soap message without invoking the service
-  std::string WsdlInvoker::getSoapMessage();
+  std::string getSoapMessage();
 
   void setProxy(const std::string & host,int  port=80);
   //enable logging
