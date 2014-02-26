--- ./rip/packets.hh.orig	2011-03-16 21:16:12.000000000 +0000
+++ ./rip/packets.hh	2014-02-26 21:17:13.000000000 +0000
@@ -586,6 +586,7 @@
     const uint8_t* _key_id;	// Key number used
     const uint8_t* _auth_bytes;	// Auth data length at end of packet
     const uint8_t* _seqno;	// Monotonically increasing seqno
+public:
     const uint8_t* _mbz;	// Must-be-zero
 };
 
