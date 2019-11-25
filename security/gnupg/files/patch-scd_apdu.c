--- scd/apdu.c.orig	2019-07-09 09:08:45 UTC
+++ scd/apdu.c
@@ -816,7 +816,7 @@ connect_pcsc_card (int slot)
 
   err = pcsc_connect (reader_table[slot].pcsc.context,
                       reader_table[slot].rdrname,
-                      PCSC_SHARE_EXCLUSIVE,
+                      opt.shared_access ? PCSC_SHARE_SHARED : PCSC_SHARE_EXCLUSIVE,
                       PCSC_PROTOCOL_T0|PCSC_PROTOCOL_T1,
                       &reader_table[slot].pcsc.card,
                       &reader_table[slot].pcsc.protocol);
