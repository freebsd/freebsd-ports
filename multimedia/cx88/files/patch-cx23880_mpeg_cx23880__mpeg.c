--- cx23880/mpeg/cx23880_mpeg.c.orig	2022-07-26 16:16:15 UTC
+++ cx23880/mpeg/cx23880_mpeg.c
@@ -173,8 +173,6 @@ static int cx23880_mpeg_request_reconfig(device_t dev)
    return cx88_mpeg_request_reconfig(&(sc->mpeg));
 }
  
-static devclass_t cx23880_mpeg_devclass; 
-
 /* DEVMETHODs */
 static device_method_t cx23880_mpeg_methods[] = 
 {
@@ -203,8 +201,13 @@ static driver_t cx23880_mpeg_driver =
    0
 };
 
+#if __FreeBSD_version >= 1400058
+DRIVER_MODULE_ORDERED(cx23880mpeg, pci, cx23880_mpeg_driver, NULL, NULL, SI_ORDER_ANY);
+#else
+static devclass_t cx23880_mpeg_devclass; 
+
 DRIVER_MODULE_ORDERED(cx23880mpeg, pci, cx23880_mpeg_driver, cx23880_mpeg_devclass, NULL, NULL, SI_ORDER_ANY);
-DRIVER_MODULE_ORDERED(cx23880mpeg, cardbus, cx23880_mpeg_driver, cx23880_mpeg_devclass, NULL, NULL, SI_ORDER_ANY);
+#endif
 
 CX88_DRIVER_MODULE(cx23880mpeg);
 CX88_I2C_DRIVER_MODULE(cx23880mpeg);
