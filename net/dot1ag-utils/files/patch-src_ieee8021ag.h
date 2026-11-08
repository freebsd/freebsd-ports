--- src/ieee8021ag.h.orig	2026-08-16 07:27:42 UTC
+++ src/ieee8021ag.h
@@ -209,7 +209,7 @@ struct cfm_lbm {
 #define GET_MD_LEVEL(s)		(((s)->octet1.md_level >> 5) & 0x07)
 
 /* positions of headers in Ethernet frame */
-#define IS_TAGGED(s)		(*(s + ETHER_ADDR_LEN * 2) \
+#define IS_TAGGED(s)		(((const struct cfmencap *)(s))->tpid \
 					== htons(ETYPE_8021Q))
 #define CFMHDR(s)		(struct cfmhdr *) \
 				(IS_TAGGED(s) ? \
