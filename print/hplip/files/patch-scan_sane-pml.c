--- scan/sane/pml.c.orig	Tue May 23 15:13:18 2006
+++ scan/sane/pml.c	Tue May 23 15:13:55 2006
@@ -725,7 +725,7 @@
    IP_IMAGE_TRAITS traits;
    IP_XFORM_SPEC xforms[IP_MAX_XFORMS], * pXform = xforms;
    int stat = SANE_STATUS_DEVICE_BUSY;
-   int i, bsize, state, wResult, index, r;
+   int i, bsize, state, wResult, index, r, mmWidth;
    int oldStuff = (hpaio->preDenali || hpaio->fromDenali || hpaio->denali) ? 1 : 0;
 
    if (hpaio->cmd_channelid < 0)
@@ -919,7 +919,7 @@
       hpaio->scanParameters.lines = MILLIMETERS_TO_PIXELS(hpaio->bryRange.max, hpaio->effectiveResolution);
    }
 
-   int mmWidth = PIXELS_TO_MILLIMETERS(traits.iPixelsPerRow, hpaio->effectiveResolution);
+   mmWidth = PIXELS_TO_MILLIMETERS(traits.iPixelsPerRow, hpaio->effectiveResolution);
 
    /* Set up X_CROP xform. */
    pXform->aXformInfo[IP_CROP_LEFT].dword = MILLIMETERS_TO_PIXELS( hpaio->effectiveTlx, hpaio->effectiveResolution );
