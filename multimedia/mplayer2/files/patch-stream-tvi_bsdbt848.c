--- stream/tvi_bsdbt848.c.orig	2013-07-09 16:33:36 UTC
+++ stream/tvi_bsdbt848.c
@@ -368,11 +368,11 @@ static int control(priv_t *priv, int cmd
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
@@ -393,7 +393,7 @@ static int control(priv_t *priv, int cmd
 
         if(req_mode == TV_NORM_NTSC)
             {
-            priv->iformat = METEOR_FMT_NTSC;
+            priv->iformat = BT848_IFORM_F_NTSCM;
             priv->maxheight = NTSC_HEIGHT;
             priv->maxwidth = NTSC_WIDTH;
             priv->maxfps = NTSC_FPS;
@@ -417,9 +417,28 @@ static int control(priv_t *priv, int cmd
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
 
-        if(ioctl(priv->btfd, METEORSFMT, &priv->iformat) < 0)
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
+
+        if(ioctl(priv->btfd, BT848SFMT, &priv->iformat) < 0)
             {
             mp_tmsg(MSGT_TV, MSGL_ERR, "tvi_bsdbt848: Call to %s ioctl failed. Error: %s\n", "METEORSFMT", strerror(errno));
             return TVI_CONTROL_FALSE;
@@ -548,8 +567,9 @@ G_private = priv; /* Oooh, sick */
 /* Video Configuration */
 
 priv->videoready = TRUE;
+priv->btdev = strdup("/dev/bktr0");
 priv->immediatemode = FALSE;
-priv->iformat = METEOR_FMT_PAL;
+priv->iformat = BT848_IFORM_F_PALBDGHI;
 priv->maxheight = PAL_HEIGHT;
 priv->maxwidth = PAL_WIDTH;
 priv->maxfps = PAL_FPS;
@@ -574,7 +594,7 @@ if(priv->btfd < 0)
     }
 
 if(priv->videoready == TRUE &&
-   ioctl(priv->btfd, METEORSFMT, &priv->iformat) < 0)
+   ioctl(priv->btfd, BT848SFMT, &priv->iformat) < 0)
     {
     mp_tmsg(MSGT_TV, MSGL_ERR, "tvi_bsdbt848: Call to %s ioctl failed. Error: %s\n", "SETEORSFMT", strerror(errno));
     }
