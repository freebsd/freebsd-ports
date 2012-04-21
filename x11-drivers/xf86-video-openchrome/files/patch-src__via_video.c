Fix Xvideo crash in X.org server 1.10

http://cgit.freedesktop.org/openchrome/xf86-video-openchrome/commit/?id=cd753845e02466b81f426793e4f5619afab05d82

--- src/via_video.c.orig	2012-02-08 10:13:54.000000000 +0100
+++ src/via_video.c	2012-02-08 10:14:33.000000000 +0100
@@ -763,67 +763,6 @@
     return 0;
 }
 
-
-/*
- * This one gets called, for example, on panning.
- */
-
-static int
-viaReputImage(ScrnInfoPtr pScrn,
-        short drw_x, short drw_y, RegionPtr clipBoxes, pointer data,
-        DrawablePtr pDraw)
-{
-
-    DDUPDATEOVERLAY UpdateOverlay_Video;
-    LPDDUPDATEOVERLAY lpUpdateOverlay = &UpdateOverlay_Video;
-    viaPortPrivPtr pPriv = (viaPortPrivPtr) data;
-    VIAPtr pVia = VIAPTR(pScrn);
-
-    if (!RegionsEqual(&pPriv->clip, clipBoxes)) {
-        REGION_COPY(pScrn->pScreen, &pPriv->clip, clipBoxes);
-        if (pPriv->autoPaint) {
-            if (pDraw->type == DRAWABLE_WINDOW) {
-                viaPaintColorkey(pScrn, pPriv, clipBoxes, pDraw);
-            } else {
-                xf86XVFillKeyHelper(pScrn->pScreen, pPriv->colorKey,
-                    clipBoxes);
-            }
-        }
-    }
-
-    if (drw_x == pPriv->old_drw_x &&
-        drw_y == pPriv->old_drw_y &&
-        pVia->swov.oldPanningX == pVia->swov.panning_x &&
-        pVia->swov.oldPanningY == pVia->swov.panning_y) {
-        viaXvError(pScrn, pPriv, xve_none);
-        return Success;
-    }
-
-    lpUpdateOverlay->SrcLeft = pPriv->old_src_x;
-    lpUpdateOverlay->SrcTop = pPriv->old_src_y;
-    lpUpdateOverlay->SrcRight = pPriv->old_src_x + pPriv->old_src_w;
-    lpUpdateOverlay->SrcBottom = pPriv->old_src_y + pPriv->old_src_h;
-
-    lpUpdateOverlay->DstLeft = drw_x;
-    lpUpdateOverlay->DstTop = drw_y;
-    lpUpdateOverlay->DstRight = drw_x + pPriv->old_drw_w;
-    lpUpdateOverlay->DstBottom = drw_y + pPriv->old_drw_h;
-    pPriv->old_drw_x = drw_x;
-    pPriv->old_drw_y = drw_y;
-
-    lpUpdateOverlay->dwFlags = DDOVER_KEYDEST;
-
-    if (pScrn->bitsPerPixel == 8)
-        lpUpdateOverlay->dwColorSpaceLowValue = pPriv->colorKey & 0xff;
-    else
-        lpUpdateOverlay->dwColorSpaceLowValue = pPriv->colorKey;
-
-    VIAVidUpdateOverlay(pScrn, lpUpdateOverlay);
-
-    viaXvError(pScrn, pPriv, xve_none);
-    return Success;
-}
-
 static unsigned
 viaSetupAdaptors(ScreenPtr pScreen, XF86VideoAdaptorPtr ** adaptors)
 {
@@ -884,7 +823,7 @@
         viaAdaptPtr[i]->GetPortAttribute = viaGetPortAttribute;
         viaAdaptPtr[i]->SetPortAttribute = viaSetPortAttribute;
         viaAdaptPtr[i]->PutImage = viaPutImage;
-        viaAdaptPtr[i]->ReputImage = viaReputImage;
+        viaAdaptPtr[i]->ReputImage = NULL;
         viaAdaptPtr[i]->QueryImageAttributes = viaQueryImageAttributes;
         for (j = 0; j < numPorts; ++j) {
             viaPortPriv[j].dmaBounceBuffer = NULL;
