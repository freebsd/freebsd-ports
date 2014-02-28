--- ./libproto/packet.cc.orig	2011-03-16 21:27:50.000000000 +0000
+++ ./libproto/packet.cc	2014-02-26 21:17:13.000000000 +0000
@@ -233,7 +233,7 @@
 }
 
 ArpHeader::ArpHeader() {
-    memset(this, 0, sizeof(this));
+    memset(this, 0, sizeof(*this));
     ah_hw_len = 6;
     ah_proto_len = 4;
 }
