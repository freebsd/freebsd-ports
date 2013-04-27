--- ext/libvisual/visual.c.orig	2013-03-28 03:21:27.000000000 +0000
+++ ext/libvisual/visual.c	2013-03-28 03:22:29.000000000 +0000
@@ -300,9 +300,9 @@
 
   }
 #else
-  if (channels == 2) {
     guint16 *ldata = visual->audio->plugpcm[0];
     guint16 *rdata = visual->audio->plugpcm[1];
+  if (channels == 2) {
     for (i = 0; i < VISUAL_SAMPLES; i++) {
       ldata[i] = *adata++;
       rdata[i] = *adata++;
