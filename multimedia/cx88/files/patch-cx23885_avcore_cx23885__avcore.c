--- cx23885/avcore/cx23885_avcore.c.orig	2022-07-26 16:27:33 UTC
+++ cx23885/avcore/cx23885_avcore.c
@@ -45,9 +45,6 @@
 
 #define CX23885AV_I2C_TIMEOUT      (hz / 8)
 
-static devclass_t cx23885av_devclass;
-static devclass_t cx23885adc_devclass;
-
 typedef struct
 {
    uint32_t hactive;
@@ -1260,7 +1257,13 @@ static driver_t cx23885av_driver =
    sizeof(cx23885av_softc)
 };
 
+#if __FreeBSD_version >= 1400058
+DRIVER_MODULE(cx23885av, iicbus, cx23885av_driver, NULL, NULL);
+#else
+static devclass_t cx23885av_devclass;
+
 DRIVER_MODULE(cx23885av, iicbus, cx23885av_driver, cx23885av_devclass, NULL, NULL);
+#endif
 MODULE_DEPEND(cx23885av, iicbus, IICBUS_MINVER, IICBUS_MODVER, IICBUS_MAXVER);
 MODULE_DEPEND(cx23885av, firmware, 1, 1, 1);
 MODULE_DEPEND(cx23885av, cx88audiocore, CX88_AUDIO_MINVER, CX88_AUDIO_MODVER, CX88_AUDIO_MAXVER);
@@ -1318,6 +1321,12 @@ static driver_t cx23885adc_driver =
    0
 };
 
+#if __FreeBSD_version >= 1400058
+DRIVER_MODULE(cx23885adc, iicbus, cx23885adc_driver, NULL, NULL);
+#else
+static devclass_t cx23885adc_devclass;
+
 DRIVER_MODULE(cx23885adc, iicbus, cx23885adc_driver, cx23885adc_devclass, NULL, NULL);
+#endif
 MODULE_DEPEND(cx23885adc, iicbus, IICBUS_MINVER, IICBUS_MODVER, IICBUS_MAXVER);
 MODULE_VERSION(cx23885adc, CX23885ADC_MODVER);
