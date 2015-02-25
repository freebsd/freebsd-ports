--- src/ecp_dese.h.orig	2013-06-11 09:00:00 UTC
+++ src/ecp_dese.h
@@ -30,11 +30,11 @@
   
   struct desinfo
   {
-    des_cblock		xmit_ivec;	/* Xmit initialization vector */
-    des_cblock		recv_ivec;	/* Recv initialization vector */
+    DES_cblock		xmit_ivec;	/* Xmit initialization vector */
+    DES_cblock		recv_ivec;	/* Recv initialization vector */
     u_int16_t		xmit_seq;	/* Transmit sequence number */
     u_int16_t		recv_seq;	/* Receive sequence number */
-    des_key_schedule	ks;		/* Key schedule */
+    DES_key_schedule	ks;		/* Key schedule */
     struct dese_stats	recv_stats;	
     struct dese_stats	xmit_stats;	
   };
