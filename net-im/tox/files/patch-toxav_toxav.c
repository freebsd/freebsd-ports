--- toxav/toxav.c.orig	2014-05-31 21:36:37.000000000 +0200
+++ toxav/toxav.c	2014-06-02 00:11:25.000000000 +0200
@@ -532,7 +532,7 @@
         if (pkt->kind == VPX_CODEC_CX_FRAME_PKT) {
             if ( copied + pkt->data.frame.sz > dest_max ) return ErrorPacketTooLarge;
 
-            mempcpy(dest + copied, pkt->data.frame.buf, pkt->data.frame.sz);
+            memcpy(dest + copied, pkt->data.frame.buf, pkt->data.frame.sz);
             copied += pkt->data.frame.sz;
         }
     }
@@ -713,4 +713,4 @@
 inline__ Tox *toxav_get_tox(ToxAv *av)
 {
     return (Tox *)av->messenger;
-}
\ No newline at end of file
+}
