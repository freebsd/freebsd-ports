--- tools/cycmd.cpp.orig	Sun Oct  2 18:15:03 2005
+++ tools/cycmd.cpp	Sun Oct  2 18:15:34 2005
@@ -589,7 +589,7 @@
 int Interactive<Stream>::negotiate()
 {
     // Do client negotiation with the server
-    Atlas::Net::StreamConnect conn("cycmd", ios, *this);
+    Atlas::Net::StreamConnect conn("cycmd", ios);
 
     std::cout << "Negotiating... " << std::flush;
     while (conn.getState() == Atlas::Negotiate::IN_PROGRESS) {
@@ -606,7 +606,7 @@
     // Negotiation was successful
 
     // Get the codec that negotiation established
-    codec = conn.getCodec();
+    codec = conn.getCodec(*this);
 
     // Create the encoder
     encoder = new Atlas::Objects::ObjectsEncoder(*codec);
