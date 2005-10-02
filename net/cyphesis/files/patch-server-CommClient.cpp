--- server/CommClient.cpp.orig	Sun Oct  2 18:09:37 2005
+++ server/CommClient.cpp	Sun Oct  2 18:11:05 2005
@@ -28,7 +28,7 @@
 {
     m_clientIos.setTimeout(0,1000);
 
-    m_negotiate = new Atlas::Net::StreamAccept("cyphesis " + m_commServer.m_server.getName(), m_clientIos, *this);
+    m_negotiate = new Atlas::Net::StreamAccept("cyphesis " + m_commServer.m_server.getName(), m_clientIos);
 }
 
 CommClient::CommClient(CommServer & svr, BaseEntity & c) :
@@ -38,7 +38,7 @@
 {
     m_clientIos.setTimeout(0,1000);
 
-    m_negotiate = new Atlas::Net::StreamConnect("cyphesis " + m_commServer.m_server.getName(), m_clientIos, *this);
+    m_negotiate = new Atlas::Net::StreamConnect("cyphesis " + m_commServer.m_server.getName(), m_clientIos);
 }
 
 CommClient::~CommClient()
@@ -85,7 +85,7 @@
     // Negotiation was successful
 
     // Get the codec that negotiation established
-    m_codec = m_negotiate->getCodec();
+    m_codec = m_negotiate->getCodec(*this);
 
     // Create a new encoder to send high level objects to the codec
     m_encoder = new Atlas::Objects::ObjectsEncoder(*m_codec);
