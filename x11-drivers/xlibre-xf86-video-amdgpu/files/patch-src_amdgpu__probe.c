--- src/amdgpu_probe.c.orig	2025-12-26 00:17:12 UTC
+++ src/amdgpu_probe.c
@@ -86,24 +86,6 @@ static Bool amdgpu_kernel_mode_enabled(ScrnInfoPtr pSc
 
 static Bool amdgpu_kernel_mode_enabled(ScrnInfoPtr pScrn)
 {
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
-	AMDGPUEntPtr pAMDGPUEnt = AMDGPUEntPriv(pScrn);
-	const char *busIdString = pAMDGPUEnt->busid;
-	int ret = drmCheckModesettingSupported(busIdString);
-
-	if (ret) {
-		if (xf86LoadKernelModule("amdgpukms"))
-			ret = drmCheckModesettingSupported(busIdString);
-	}
-	if (ret) {
-		xf86DrvMsgVerb(pScrn->scrnIndex, X_INFO, 0,
-			       "[KMS] drm report modesetting isn't supported.\n");
-		return FALSE;
-	}
-
-#endif
-	xf86DrvMsgVerb(pScrn->scrnIndex, X_INFO, 0,
-		       "[KMS] Kernel modesetting enabled.\n");
 	return TRUE;
 }
 
