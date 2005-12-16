--- libmpdemux/tvi_bsdbt848.c.orig	Tue Dec 28 04:30:14 2004
+++ libmpdemux/tvi_bsdbt848.c	Fri Dec 16 20:42:14 2005
@@ -296,11 +296,11 @@
         int req_mode = (int)*(void **)arg;
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
@@ -321,7 +321,7 @@
 
         if(req_mode == TV_NORM_NTSC) 
             {
-            priv->iformat = METEOR_FMT_NTSC;
+            priv->iformat = BT848_IFORM_F_NTSCM;
             priv->maxheight = NTSC_HEIGHT;
             priv->maxwidth = NTSC_WIDTH;
             priv->maxfps = NTSC_FPS;
@@ -345,9 +345,28 @@
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
@@ -478,7 +497,7 @@
 priv->videoready = TRUE;
 priv->btdev = strdup("/dev/bktr0");
 priv->immediatemode = FALSE;
-priv->iformat = METEOR_FMT_PAL;
+priv->iformat = BT848_IFORM_F_PALBDGHI;
 priv->maxheight = PAL_HEIGHT;
 priv->maxwidth = PAL_WIDTH;
 priv->maxfps = PAL_FPS;
@@ -503,7 +522,7 @@
     }
 
 if(priv->videoready == TRUE && 
-   ioctl(priv->btfd, METEORSFMT, &priv->iformat) < 0) 
+   ioctl(priv->btfd, BT848SFMT, &priv->iformat) < 0) 
     {
     perror("FMT:ioctl");
     }
