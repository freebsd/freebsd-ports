--- src/stream.h~	Sun Dec 11 21:09:14 2005
+++ src/stream.h	Mon Apr  9 16:55:43 2007
@@ -54,6 +54,8 @@
     avcc->bit_rate=9500000;
     avcc->rc_max_rate=9500000;
     avcc->rc_buffer_size=224*1024*8;
+    avcc->rc_buffer_aggressivity=1.0;
+    avcc->rc_initial_buffer_occupancy = avcc->rc_buffer_size*3/4;
     avcc->qmax=2;
     avcc->mb_lmax= FF_QP2LAMBDA * 2;
     avcc->lmax= FF_QP2LAMBDA * 2;
