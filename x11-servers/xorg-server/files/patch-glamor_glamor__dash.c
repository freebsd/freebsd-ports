From: Eric Anholt <eric@anholt.net>
Date: Wed Mar 15 17:51:46 2017 -0700
Subject: [PATCH]glamor: Fix dashed line rendering.
Patch-mainline: fe0b297420fc1de8a7fab28457d0864b3182e967
References: boo#1021803
Signed-off-by: Max Staudt <mstaudt@suse.de>

We were binding the screen pixmap as the dash and sampling its alpha,
which is usually just 1.0 (no dashing at all).

Please cherry-pick this to active stable branches.

Signed-off-by: Eric Anholt <eric@anholt.net>
Reviewed-by: Keith Packard <keithp@keithp.com>
Reviewed-by: Michel Dänzer <michel.daenzer@amd.com>

--- glamor/glamor_dash.c.orig	2016-07-18 19:08:16 UTC
+++ glamor/glamor_dash.c
@@ -146,7 +146,7 @@ glamor_dash_setup(DrawablePtr drawable, GCPtr gc)
         goto bail;
 
     dash_pixmap = glamor_get_dash_pixmap(gc);
-    dash_priv = glamor_get_pixmap_private(pixmap);
+    dash_priv = glamor_get_pixmap_private(dash_pixmap);
 
     if (!GLAMOR_PIXMAP_PRIV_HAS_FBO(dash_priv))
         goto bail;
