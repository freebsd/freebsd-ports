--- cx23880/video/cx23880_video.c.orig	2022-07-26 16:17:40 UTC
+++ cx23880/video/cx23880_video.c
@@ -519,8 +519,6 @@ static int cx23880_video_request_reconfig(device_t dev
    return cx88_video_request_reconfig(&(sc->video));
 }
  
-static devclass_t cx23880_video_devclass;
-
 /* DEVMETHODs */
 static device_method_t cx23880_video_methods[] = 
 {
@@ -561,8 +559,13 @@ static driver_t cx23880_video_driver =
    0
 };
 
+#if __FreeBSD_version >= 1400058
+DRIVER_MODULE_ORDERED(cx23880video, pci, cx23880_video_driver, NULL, NULL, SI_ORDER_ANY);
+#else
+static devclass_t cx23880_video_devclass;
+
 DRIVER_MODULE_ORDERED(cx23880video, pci, cx23880_video_driver, cx23880_video_devclass, NULL, NULL, SI_ORDER_ANY);
-DRIVER_MODULE_ORDERED(cx23880video, cardbus, cx23880_video_driver, cx23880_video_devclass, NULL, NULL, SI_ORDER_ANY);
+#endif
 
 CX88_DRIVER_MODULE(cx23880video);
 CX88_I2C_DRIVER_MODULE(cx23880video);
