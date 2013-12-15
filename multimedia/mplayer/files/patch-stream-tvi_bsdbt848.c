--- stream/tvi_bsdbt848.c.orig	2013-03-16 11:15:07.000000000 +0100
+++ stream/tvi_bsdbt848.c	2013-11-09 13:47:43.804868208 +0100
@@ -366,11 +366,11 @@
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
@@ -391,7 +391,7 @@
 
         if(req_mode == TV_NORM_NTSC)
             {
-            priv->iformat = METEOR_FMT_NTSC;
+            priv->iformat = BT848_IFORM_F_NTSCM;
             priv->maxheight = NTSC_HEIGHT;
             priv->maxwidth = NTSC_WIDTH;
             priv->maxfps = NTSC_FPS;
@@ -415,9 +415,28 @@
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
@@ -546,8 +565,9 @@
 /* Video Configuration */
 
 priv->videoready = 1;
+priv->btdev = strdup("/dev/bktr0");
 priv->immediatemode = 0;
-priv->iformat = METEOR_FMT_PAL;
+priv->iformat = BT848_IFORM_F_PALBDGHI;
 priv->maxheight = PAL_HEIGHT;
 priv->maxwidth = PAL_WIDTH;
 priv->maxfps = PAL_FPS;
@@ -572,7 +592,7 @@
     }
 
 if(priv->videoready &&
-   ioctl(priv->btfd, METEORSFMT, &priv->iformat) < 0)
+   ioctl(priv->btfd, BT848SFMT, &priv->iformat) < 0)
     {
     mp_msg(MSGT_TV, MSGL_ERR, MSGTR_TV_Bt848IoctlFailed, "SETEORSFMT", strerror(errno));
     }
