--- src/mod_sipxauth/SIPXAuthHandler.cpp.orig	Sun Feb 11 18:35:47 2007
+++ src/mod_sipxauth/SIPXAuthHandler.cpp	Sun Feb 11 18:41:37 2007
@@ -168,7 +168,7 @@
     rPidStr = temp;
 }
 
-SIPXAuthHandler::SIPXAuthHandler() : ApacheHandler()
+SIPXAuthHandler::SIPXAuthHandler(ApacheServerRec *pRequest) : ApacheHandler(pRequest)
 {
     // do NOT Initialize the IMDB Singleton - Note this is called
     // running as user root so delay until running as user apache
@@ -625,9 +625,9 @@
 
 /*=====================INSTANCIATORS==========================*/
 
-ApacheHandler *instanciate_auth()
+ApacheHandler *instanciate_auth(ApacheServerRec *pServer)
 {
-    return new SIPXAuthHandler();
+    return new SIPXAuthHandler(pServer);
 }
 
 // Make sure this symbol is exported and also it is crucial
