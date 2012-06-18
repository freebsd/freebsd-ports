--- src/wcmConfig.c.orig
+++ src/wcmConfig.c
@@ -373,9 +373,12 @@ wcmDetectDeviceClass(const InputInfoPtr 
 		return TRUE;
 
 	/* Bluetooth is also considered as USB */
+#if 0
 	if (gWacomISDV4Device.Detect(pInfo))
 		common->wcmDevCls = &gWacomISDV4Device;
-	else if (gWacomUSBDevice.Detect(pInfo))
+	else
+#endif
+	if (gWacomUSBDevice.Detect(pInfo))
 		common->wcmDevCls = &gWacomUSBDevice;
 	else
 		xf86Msg(X_ERROR, "%s: cannot identify device class.\n", pInfo->name);
