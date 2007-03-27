--- lips/gdevlprn.c.orig	Thu Nov  2 12:09:18 2000
+++ lips/gdevlprn.c	Fri Dec 17 19:21:08 2004
@@ -219,13 +219,13 @@
     maxBy = (pdev->height + lprn->nBh - 1) / lprn->nBh;
     maxY = lprn->BlockLine / lprn->nBh * lprn->nBh;
 
-    if (!(lprn->ImageBuf = gs_malloc(bpl, maxY, "lprn_print_image(ImageBuf)")))
+    if (!(lprn->ImageBuf = gs_malloc(pdev->memory, bpl, maxY, "lprn_print_image(ImageBuf)")))
 	return_error(gs_error_VMerror);
-    if (!(lprn->TmpBuf = gs_malloc(bpl, maxY, "lprn_print_iamge(TmpBuf)")))
+    if (!(lprn->TmpBuf = gs_malloc(pdev->memory, bpl, maxY, "lprn_print_iamge(TmpBuf)")))
 	return_error(gs_error_VMerror);
-    if (!(lprn->bubbleTbl = gs_malloc(sizeof(Bubble *), maxBx, "lprn_print_image(bubbleTbl)")))
+    if (!(lprn->bubbleTbl = gs_malloc(pdev->memory, sizeof(Bubble *), maxBx, "lprn_print_image(bubbleTbl)")))
 	return_error(gs_error_VMerror);
-    if (!(bubbleBuffer = gs_malloc(sizeof(Bubble), maxBx, "lprn_print_image(bubbleBuffer)")))
+    if (!(bubbleBuffer = gs_malloc(pdev->memory, sizeof(Bubble), maxBx, "lprn_print_image(bubbleBuffer)")))
 	return_error(gs_error_VMerror);
 
     for (i = 0; i < maxBx; i++)
@@ -261,10 +261,10 @@
     }
     lprn_bubble_flush_all(pdev, fp);	/* flush the rest of bubble */
 
-    gs_free(lprn->ImageBuf, bpl, maxY, "lprn_print_image(ImageBuf)");
-    gs_free(lprn->TmpBuf, bpl, maxY, "lprn_print_iamge(TmpBuf)");
-    gs_free(lprn->bubbleTbl, sizeof(Bubble *), maxBx, "lprn_print_image(bubbleTbl)");
-    gs_free(bubbleBuffer, sizeof(Bubble), maxBx, "lprn_print_image(bubbleBuffer)");
+    gs_free(pdev->memory, lprn->ImageBuf, bpl, maxY, "lprn_print_image(ImageBuf)");
+    gs_free(pdev->memory, lprn->TmpBuf, bpl, maxY, "lprn_print_iamge(TmpBuf)");
+    gs_free(pdev->memory, lprn->bubbleTbl, sizeof(Bubble *), maxBx, "lprn_print_image(bubbleTbl)");
+    gs_free(pdev->memory, bubbleBuffer, sizeof(Bubble), maxBx, "lprn_print_image(bubbleBuffer)");
 
     return code;
 }
