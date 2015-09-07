--- rip/packets.hh.orig	2012-01-11 17:56:10 UTC
+++ rip/packets.hh
@@ -586,6 +586,7 @@ private:
     const uint8_t* _key_id;	// Key number used
     const uint8_t* _auth_bytes;	// Auth data length at end of packet
     const uint8_t* _seqno;	// Monotonically increasing seqno
+public:
     const uint8_t* _mbz;	// Must-be-zero
 };
 
