--- epan/dissectors/packet-ieee80211.c.orig	Wed Apr 26 22:19:29 2006
+++ epan/dissectors/packet-ieee80211.c	Wed Apr 26 22:19:58 2006
@@ -723,7 +723,7 @@ find_header_length (guint16 fcf)
   case DATA_FRAME:
     len = (FCF_ADDR_SELECTOR(fcf) == DATA_ADDR_T4) ? DATA_LONG_HDR_LEN :
 						      DATA_SHORT_HDR_LEN;
-    if (DATA_FRAME_IS_QOS(COMPOSE_FRAME_TYPE(fcf)))
+    if (COMPOSE_FRAME_TYPE(fcf) == DATA_QOS_DATA)
       return len + 2;
     else
       return len;
