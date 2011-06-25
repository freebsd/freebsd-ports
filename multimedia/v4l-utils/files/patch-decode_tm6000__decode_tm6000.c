--- ./decode_tm6000/decode_tm6000.c.orig	2011-02-09 23:04:27.000000000 +0100
+++ ./decode_tm6000/decode_tm6000.c	2011-06-03 19:08:13.000000000 +0200
@@ -41,6 +41,8 @@
 	{ 0, 0, 0, 0, 0, 0 }
 };
 
+#define devname dev_name
+
 static char outbuf[692224];
 static int debug=0, audio=0, use_mmap=1, nbufs=4;
 static float freq_mhz=193.25;
