--- src/decode.c.orig	2018-10-06 13:07:26 UTC
+++ src/decode.c
@@ -265,9 +265,9 @@ int DecodePacket(int linktype, Packet *p
     return 0;
 }
 
-static INLINE void DecoderEvent(
-    Packet *p, int gid, char *str, int event_flag, int drop_flag) 
-{
+//static INLINE void DecoderEvent(
+//    Packet *p, int gid, char *str, int event_flag, int drop_flag) 
+//{
 //    if((runMode == MODE_IDS) && event_flag) 
 //    {
 //        SnortEventqAdd(GENERATOR_SNORT_DECODE, gid, 1, 
@@ -278,7 +278,7 @@ static INLINE void DecoderEvent(
 //            InlineDrop(p);
 //        }
 //    }
-}
+//}
 
 /*
  * Function: DecodeEthPkt(Packet *, char *, struct pcap_pkthdr*, uint8_t*)
