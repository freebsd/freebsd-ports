--- src/headers.h-orig	2014-07-18 09:58:12 UTC
+++ src/headers.h
@@ -120,7 +120,6 @@
     #define TH_URG 0x20
     #define TH_ECE 0x40
     #define TH_CWR 0x80
-    #define TH_FLAGS (TH_FIN|TH_SYN|TH_RST|TH_ACK|TH_URG|TH_ECE|TH_CWR)
     u_short th_win; /* window */
     u_short th_sum; /* checksum */
     u_short th_urp; /* urgent pointer */
