--- talk/p2p/base/sessionmanager.h.orig	2008-09-06 23:28:33.000000000 -0300
+++ talk/p2p/base/sessionmanager.h	2008-09-06 23:28:56.000000000 -0300
@@ -156,7 +156,7 @@
 
   // Creates and returns an error message from the given components.  The
   // caller is responsible for deleting this.
-  buzz::XmlElement* SessionManager::CreateErrorMessage(
+  buzz::XmlElement* CreateErrorMessage(
       const buzz::XmlElement* stanza,
       const buzz::QName& name,
       const std::string& type,
