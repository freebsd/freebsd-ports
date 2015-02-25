--- src/ecp_dese_bis.h.orig	2013-06-11 09:00:00 UTC
+++ src/ecp_dese_bis.h
@@ -30,11 +30,11 @@
   
   struct desebisinfo
   {
-    des_cblock		xmit_ivec;	/* Xmit initialization vector */
-    des_cblock		recv_ivec;	/* Recv initialization vector */
+    DES_cblock		xmit_ivec;	/* Xmit initialization vector */
+    DES_cblock		recv_ivec;	/* Recv initialization vector */
     u_int16_t		xmit_seq;	/* Transmit sequence number */
     u_int16_t		recv_seq;	/* Receive sequence number */
-    des_key_schedule	ks;		/* Key schedule */
+    DES_key_schedule	ks;		/* Key schedule */
     struct desebis_stats recv_stats;	
     struct desebis_stats xmit_stats;	
   };
