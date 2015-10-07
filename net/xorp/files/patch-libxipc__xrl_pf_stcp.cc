--- libxipc/xrl_pf_stcp.cc.orig	2012-01-11 17:56:10 UTC
+++ libxipc/xrl_pf_stcp.cc
@@ -584,7 +584,7 @@ public:
 		 uint32_t	  sn,
 		 const Xrl&	  x,
 		 const Callback&  cb)
-	: _p(p), _sn(sn), _b(_buffer), _cb(cb), _keepalive(false)
+	: _p(p), _sn(sn), _b(_buffer), _cb(cb) //, _keepalive(false)
     {
 	size_t header_bytes = STCPPacketHeader::header_size();
 	size_t xrl_bytes = x.packed_bytes();
@@ -607,7 +607,7 @@ public:
     }
 
     RequestState(XrlPFSTCPSender* p, uint32_t sn)
-	: _p(p), _sn(sn), _b(_buffer), _keepalive(true)
+	: _p(p), _sn(sn), _b(_buffer) //, _keepalive(true)
     {
 	size_t header_bytes = STCPPacketHeader::header_size();
 
@@ -650,7 +650,7 @@ private:
     uint8_t		_buffer[256];	// XXX important performance parameter
     uint32_t		_size;
     Callback		_cb;
-    bool		_keepalive;
+    // bool		_keepalive;
 };
 
 
