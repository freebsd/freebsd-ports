--- vmwgfx/vmwgfx_dri2.c.orig	2023-01-24 02:52:01 UTC
+++ vmwgfx/vmwgfx_dri2.c
@@ -442,18 +442,13 @@ xorg_dri2_init(ScreenPtr pScreen)
      * os-specific. Currently this works only for Linux.
      */
     {
-	char fdPath[VMWGFX_FD_PATH_LEN];
-	ssize_t numChar;
-
-	memset(fdPath, 0, VMWGFX_FD_PATH_LEN);
-	snprintf(fdPath, VMWGFX_FD_PATH_LEN - 1, "/proc/self/fd/%d", ms->fd);
-	numChar = readlink(fdPath, ms->dri2_device_name, VMWGFX_DRI_DEVICE_LEN);
-	if (numChar <= 0 || numChar >= VMWGFX_DRI_DEVICE_LEN) {
+	dev_name = drmGetDeviceNameFromFd2(ms->fd);
+	if (!dev_name) {
 	    xf86DrvMsg(pScrn->scrnIndex, X_ERROR,
 		       "Could not find the drm device name. Disabling dri2.\n");
 	    return FALSE;
 	}
-	ms->dri2_device_name[numChar] = 0;
+	strncpy(ms->dri2_device_name, dev_name, VMWGFX_DRI_DEVICE_LEN);
     }
 #endif
     dri2info.deviceName = ms->dri2_device_name;
@@ -478,6 +473,7 @@ xorg_dri2_init(ScreenPtr pScreen)
 	dri2info.AuthMagic3 = vmw_dri_auth_magic3;
     }
 #endif
+	free(dev_name);
 
     return DRI2ScreenInit(pScreen, &dri2info);
 }
