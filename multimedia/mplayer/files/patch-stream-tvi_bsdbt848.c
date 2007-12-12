--- stream/tvi_bsdbt848.c.orig	2007-10-08 03:49:26.000000000 +0800
+++ stream/tvi_bsdbt848.c	2007-11-11 15:24:05.000000000 +0800
@@ -26,6 +26,7 @@
 #define NTSC_HEIGHT 480
 #define NTSC_FPS    29.97
 
+#include <errno.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
@@ -351,11 +352,11 @@
         int req_mode = *(int *)arg;
 	u_short tmp_fps;
 
-        priv->iformat = METEOR_FMT_AUTOMODE;
+        priv->iformat = BT848_IFORM_F_AUTO;
 
         if(req_mode == TV_NORM_PAL) 
             {
-            priv->iformat = METEOR_FMT_PAL;
+            priv->iformat = BT848_IFORM_F_PALBDGHI;
             priv->maxheight = PAL_HEIGHT;
             priv->maxwidth = PAL_WIDTH;
             priv->maxfps = PAL_FPS;
@@ -376,7 +377,7 @@
 
         if(req_mode == TV_NORM_NTSC) 
             {
-            priv->iformat = METEOR_FMT_NTSC;
+            priv->iformat = BT848_IFORM_F_NTSCM;
             priv->maxheight = NTSC_HEIGHT;
             priv->maxwidth = NTSC_WIDTH;
             priv->maxfps = NTSC_FPS;
@@ -400,9 +401,28 @@
                 }
             }
 
-        if(req_mode == TV_NORM_SECAM) priv->iformat = METEOR_FMT_SECAM;
+        if(req_mode == TV_NORM_SECAM)
+            {
+            priv->iformat = BT848_IFORM_F_SECAM;
+            priv->maxheight = PAL_HEIGHT;
+            priv->maxwidth = PAL_WIDTH;
+            priv->maxfps = PAL_FPS;
+            priv->fps = PAL_FPS;
+
+            if(priv->fps > priv->maxfps) priv->fps = priv->maxfps;
+
+            if(priv->geom.rows > priv->maxheight)
+                {
+                priv->geom.rows = priv->maxheight;
+                }
+
+            if(priv->geom.columns > priv->maxwidth)
+                {
+                priv->geom.columns = priv->maxwidth;
+                }
+            }
 
-        if(ioctl(priv->btfd, METEORSFMT, &priv->iformat) < 0) 
+        if(ioctl(priv->btfd, BT848SFMT, &priv->iformat) < 0) 
             {
             mp_msg(MSGT_TV, MSGL_ERR, MSGTR_TV_Bt848IoctlFailed, "METEORSFMT", strerror(errno));
             return(TVI_CONTROL_FALSE);
@@ -532,7 +552,7 @@
 
 priv->videoready = TRUE;
 priv->immediatemode = FALSE;
-priv->iformat = METEOR_FMT_PAL;
+priv->iformat = BT848_IFORM_F_PALBDGHI;
 priv->maxheight = PAL_HEIGHT;
 priv->maxwidth = PAL_WIDTH;
 priv->maxfps = PAL_FPS;
@@ -557,7 +577,7 @@
     }
 
 if(priv->videoready == TRUE && 
-   ioctl(priv->btfd, METEORSFMT, &priv->iformat) < 0) 
+   ioctl(priv->btfd, BT848SFMT, &priv->iformat) < 0) 
     {
     mp_msg(MSGT_TV, MSGL_ERR, MSGTR_TV_Bt848IoctlFailed, "SETEORSFMT", strerror(errno));
     }
