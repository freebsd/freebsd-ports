--- src/linklocalclient.cpp.orig	2015-08-11 14:37:51 UTC
+++ src/linklocalclient.cpp
@@ -55,7 +55,7 @@ namespace gloox
     bool Client::connect( const std::string& service, const std::string& type,
                           const std::string& domain, int iface )
     {
-      m_interface = interface;
+      m_interface = iface;
       return resolve( service, type, domain );
     }
 
