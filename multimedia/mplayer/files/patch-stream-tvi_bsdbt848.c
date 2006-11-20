--- stream/tvi_bsdbt848.c.orig	Mon Oct 23 00:32:25 2006
+++ stream/tvi_bsdbt848.c	Tue Oct 24 21:54:45 2006
@@ -297,11 +297,11 @@
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
@@ -322,7 +322,7 @@
 
         if(req_mode == TV_NORM_NTSC) 
             {
-            priv->iformat = METEOR_FMT_NTSC;
+            priv->iformat = BT848_IFORM_F_NTSCM;
             priv->maxheight = NTSC_HEIGHT;
             priv->maxwidth = NTSC_WIDTH;
             priv->maxfps = NTSC_FPS;
@@ -346,9 +346,28 @@
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
             perror("format:ioctl");
             return(TVI_CONTROL_FALSE);
@@ -479,7 +498,7 @@
 priv->videoready = TRUE;
 priv->btdev = strdup("/dev/bktr0");
 priv->immediatemode = FALSE;
-priv->iformat = METEOR_FMT_PAL;
+priv->iformat = BT848_IFORM_F_PALBDGHI;
 priv->maxheight = PAL_HEIGHT;
 priv->maxwidth = PAL_WIDTH;
 priv->maxfps = PAL_FPS;
@@ -504,7 +523,7 @@
     }
 
 if(priv->videoready == TRUE && 
-   ioctl(priv->btfd, METEORSFMT, &priv->iformat) < 0) 
+   ioctl(priv->btfd, BT848SFMT, &priv->iformat) < 0) 
     {
     perror("FMT:ioctl");
     }
