--- dc1394/bayer.c.orig	2016-10-11 06:19:10 UTC
+++ dc1394/bayer.c
@@ -775,7 +775,7 @@ dc1394_bayer_Downsample(const uint8_t *r
 {
 	uint8_t *outR, *outG, *outB;
 	register int i, j;
-	uint tmp;
+	int tmp;
 	int st=sx*sy;
 	int p;
 	int sx2=sx<<1;
