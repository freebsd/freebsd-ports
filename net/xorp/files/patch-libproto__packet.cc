--- libproto/packet.cc.orig	2018-07-10 12:55:07 UTC
+++ libproto/packet.cc
@@ -88,8 +88,8 @@ IpHeader4::fragment(size_t mtu, list<vec
     //
     memcpy(&frag_buf[0], _data, IpHeader4::SIZE);
     {
-	register const u_char *cp;
-	register u_char *dp;
+	const u_char *cp;
+	u_char *dp;
 	int opt, optlen, cnt;
 
 	cp = (const u_char *)(orig_ip4.data() + orig_ip4.size());
@@ -233,7 +233,7 @@ IpHeader4Writer::compute_checksum()
 }
 
 ArpHeader::ArpHeader() {
-    memset(this, 0, sizeof(this));
+    memset(this, 0, sizeof(*this));
     ah_hw_len = 6;
     ah_proto_len = 4;
 }
