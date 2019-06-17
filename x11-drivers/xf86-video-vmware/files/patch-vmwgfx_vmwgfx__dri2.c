--- vmwgfx/vmwgfx_dri2.c.orig	2018-05-17 07:42:24 UTC
+++ vmwgfx/vmwgfx_dri2.c
@@ -413,8 +413,7 @@ xorg_dri2_init(ScreenPtr pScreen)
     modesettingPtr ms = modesettingPTR(pScrn);
     DRI2InfoRec dri2info;
     int major, minor;
-    char fdPath[VMWGFX_FD_PATH_LEN];
-    ssize_t numChar;
+    const char *dev_name;
 
     memset(&dri2info, 0, sizeof(dri2info));
 
@@ -430,20 +429,13 @@ xorg_dri2_init(ScreenPtr pScreen)
     dri2info.fd = ms->fd;
     dri2info.driverName = "vmwgfx";
 
-    /*
-     * This way of obtaining the DRM device name is a bit
-     * os-specific. It would be better to obtain it from
-     * drmOpen. Currently this works only for Linux.
-     */
-    memset(fdPath, 0, VMWGFX_FD_PATH_LEN);
-    snprintf(fdPath, VMWGFX_FD_PATH_LEN - 1, "/proc/self/fd/%d", ms->fd);
-    numChar = readlink(fdPath, ms->dri2_device_name, VMWGFX_DRI_DEVICE_LEN);
-    if (numChar <= 0 || numChar >= VMWGFX_DRI_DEVICE_LEN) {
+    dev_name = drmGetDeviceNameFromFd2(ms->fd);
+    if (!dev_name) {
 	xf86DrvMsg(pScrn->scrnIndex, X_ERROR,
 		   "Could not find the drm device name. Disabling dri2.\n");
 	return FALSE;
     }
-    ms->dri2_device_name[numChar] = 0;
+	strncpy(ms->dri2_device_name, dev_name, VMWGFX_DRI_DEVICE_LEN);
     dri2info.deviceName = ms->dri2_device_name;
     xf86DrvMsg(pScrn->scrnIndex, X_INFO,
 	       "Path of drm device is \"%s\".\n", ms->dri2_device_name);
@@ -466,6 +458,7 @@ xorg_dri2_init(ScreenPtr pScreen)
 	dri2info.AuthMagic3 = vmw_dri_auth_magic3;
     }
 #endif
+	free(dev_name);
 
     return DRI2ScreenInit(pScreen, &dri2info);
 }
