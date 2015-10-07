--- libproto/packet.cc.orig	2012-01-11 17:56:10 UTC
+++ libproto/packet.cc
@@ -233,7 +233,7 @@ IpHeader4Writer::compute_checksum()
 }
 
 ArpHeader::ArpHeader() {
-    memset(this, 0, sizeof(this));
+    memset(this, 0, sizeof(*this));
     ah_hw_len = 6;
     ah_proto_len = 4;
 }
