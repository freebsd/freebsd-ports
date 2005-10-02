--- client/ClientConnection.cpp.orig	Sun Oct  2 18:13:33 2005
+++ client/ClientConnection.cpp	Sun Oct  2 18:13:55 2005
@@ -172,7 +172,7 @@
 
 int ClientConnection::negotiate()
 {
-    Atlas::Net::StreamConnect conn("cyphesis_aiclient", ios, *this);
+    Atlas::Net::StreamConnect conn("cyphesis_aiclient", ios);
 
     debug(std::cout << "Negotiating... " << std::flush;);
     while (conn.getState() == Atlas::Net::StreamConnect::IN_PROGRESS) {
@@ -185,7 +185,7 @@
         return -1;
     }
 
-    codec = conn.getCodec();
+    codec = conn.getCodec(*this);
 
     encoder = new Atlas::Objects::ObjectsEncoder(*codec);
 
