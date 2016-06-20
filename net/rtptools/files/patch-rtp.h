--- rtp.h.orig	2001-12-29 12:48:24 UTC
+++ rtp.h
@@ -112,13 +112,18 @@ typedef struct {
 #define RTCP_VALID_MASK (0xc000 | 0x2000 | 0xfe)
 #define RTCP_VALID_VALUE ((RTP_VERSION << 14) | RTCP_SR)
 
+#define	RTCP_FRACTION(x)	(((x) >> 24) & 0xFF)
+#define	RTCP_LOST(x)		((((x) & 0xFFFFFF) < 0x800000) ? \
+					((x) & 0xFFFFFF) \
+					: (((x) & 0xFFFFFF) - 0x1000000))
+
 /*
  * Reception report block
  */
 typedef struct {
     u_int32 ssrc;             /* data source being reported */
-    unsigned int fraction:8;  /* fraction lost since last SR/RR */
-    int lost:24;              /* cumul. no. pkts lost (signed!) */
+    u_int32 fraclost;	      /* fraction lost since last SR/RR and */
+			      /* cumul. no. pkts lost (signed!) */
     u_int32 last_seq;         /* extended last seq. no. received */
     u_int32 jitter;           /* interarrival jitter */
     u_int32 lsr;              /* last SR packet from this source */
