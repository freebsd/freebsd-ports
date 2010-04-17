--- src/decode_proto.c.orig	2010-04-14 16:16:43.000000000 -0300
+++ src/decode_proto.c	2010-04-14 16:17:57.000000000 -0300
@@ -165,7 +165,7 @@
  {"WLAN",   DLT_IEEE802_11,    LINK6,   get_wlan }, 
  /* Wireless with radiotap header */
  {"WLAN+RTAP",  DLT_IEEE802_11_RADIO, LINK6, get_radiotap }, 
- {"PPI",  DLT_PPI, LINK6, get_ppi }, /* PPI encapsulation */
+ /* {"PPI",  DLT_PPI, LINK6, get_ppi }, PPI encapsulation */
  {NULL,   0, 0 } /* terminating entry, must be last */
 };
 
