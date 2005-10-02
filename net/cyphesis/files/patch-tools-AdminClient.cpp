--- tools/AdminClient.cpp.orig	Sun Oct  2 18:16:32 2005
+++ tools/AdminClient.cpp	Sun Oct  2 18:16:51 2005
@@ -408,7 +408,7 @@
 int AdminClient::negotiate()
 {
     // Do client negotiation with the server
-    Atlas::Net::StreamConnect conn("cycmd", *ios, *this);
+    Atlas::Net::StreamConnect conn("cycmd", *ios);
 
     while (conn.getState() == Atlas::Negotiate::IN_PROGRESS) {
         // conn.poll() does all the negotiation
@@ -423,7 +423,7 @@
     // Negotiation was successful
 
     // Get the codec that negotiation established
-    codec = conn.getCodec();
+    codec = conn.getCodec(*this);
 
     // Create the encoder
     encoder = new Atlas::Objects::ObjectsEncoder(*codec);
