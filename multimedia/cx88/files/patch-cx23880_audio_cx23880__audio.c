--- cx23880/audio/cx23880_audio.c.orig	2022-07-26 16:22:44 UTC
+++ cx23880/audio/cx23880_audio.c
@@ -1018,8 +1018,6 @@ static int cx23880_audio_shutdown(device_t dev)
    return 0;
 }
 
-static devclass_t cx23880_audio_devclass;
-
 static device_method_t cx23880_audio_methods[] = 
 {
    /* Device interface */
@@ -1058,8 +1056,13 @@ static driver_t cx23880_audio_driver =
    0
 };
 
+#if __FreeBSD_version >= 1400058
+DRIVER_MODULE_ORDERED(cx23880audio, pci, cx23880_audio_driver, NULL, NULL, SI_ORDER_ANY);
+#else
+static devclass_t cx23880_audio_devclass;
+
 DRIVER_MODULE_ORDERED(cx23880audio, pci, cx23880_audio_driver, cx23880_audio_devclass, NULL, NULL, SI_ORDER_ANY);
-DRIVER_MODULE_ORDERED(cx23880audio, cardbus, cx23880_audio_driver, cx23880_audio_devclass, NULL, NULL, SI_ORDER_ANY);
+#endif
 
 CX88_DRIVER_MODULE(cx23880audio);
 CX88_I2C_DRIVER_MODULE(cx23880audio);
