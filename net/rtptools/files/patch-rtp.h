--- rtp.h.orig	2018-03-20 06:17:35 UTC
+++ rtp.h
@@ -130,13 +130,18 @@ typedef struct {
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
     uint32_t ssrc;             /* data source being reported */
-    unsigned int fraction:8;  /* fraction lost since last SR/RR */
-    int lost:24;              /* cumul. no. pkts lost (signed!) */
+    uint32_t fraclost;	       /* fraction lost since last SR/RR and */
+			       /* cumul. no. pkts lost (signed!) */
     uint32_t last_seq;         /* extended last seq. no. received */
     uint32_t jitter;           /* interarrival jitter */
     uint32_t lsr;              /* last SR packet from this source */
