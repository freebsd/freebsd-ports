--- stream/tvi_bsdbt848.c.orig	2009-05-12 21:58:57.000000000 -0500
+++ stream/tvi_bsdbt848.c	2009-07-23 20:39:13.536681248 -0500
@@ -352,11 +352,11 @@
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
@@ -377,7 +377,7 @@
 
         if(req_mode == TV_NORM_NTSC)
             {
-            priv->iformat = METEOR_FMT_NTSC;
+            priv->iformat = BT848_IFORM_F_NTSCM;
             priv->maxheight = NTSC_HEIGHT;
             priv->maxwidth = NTSC_WIDTH;
             priv->maxfps = NTSC_FPS;
@@ -401,9 +401,28 @@
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
             return TVI_CONTROL_FALSE;
@@ -532,8 +551,9 @@
 /* Video Configuration */
 
 priv->videoready = TRUE;
+priv->btdev = strdup("/dev/bktr0");
 priv->immediatemode = FALSE;
-priv->iformat = METEOR_FMT_PAL;
+priv->iformat = BT848_IFORM_F_PALBDGHI;
 priv->maxheight = PAL_HEIGHT;
 priv->maxwidth = PAL_WIDTH;
 priv->maxfps = PAL_FPS;
@@ -558,7 +578,7 @@
     }
 
 if(priv->videoready == TRUE &&
-   ioctl(priv->btfd, METEORSFMT, &priv->iformat) < 0)
+   ioctl(priv->btfd, BT848SFMT, &priv->iformat) < 0)
     {
     mp_msg(MSGT_TV, MSGL_ERR, MSGTR_TV_Bt848IoctlFailed, "SETEORSFMT", strerror(errno));
     }
