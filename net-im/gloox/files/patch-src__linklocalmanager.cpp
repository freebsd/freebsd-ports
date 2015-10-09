--- src/linklocalmanager.cpp.orig	2015-08-11 14:37:51 UTC
+++ src/linklocalmanager.cpp
@@ -197,7 +197,7 @@ namespace gloox
 
     void Manager::handleBrowse( Flag flag, const std::string& service, const std::string& regtype, const std::string& domain, int iface, bool moreComing )
     {
-      Service s( flag, service, regtype, domain, interface );
+      Service s( flag, service, regtype, domain, iface );
       m_tmpServices.push_back( s );
 
 //       switch( flag )
