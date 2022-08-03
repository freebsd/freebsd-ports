--- cx23885/cx23885.c.orig	2022-07-26 16:24:23 UTC
+++ cx23885/cx23885.c
@@ -508,8 +508,6 @@ static int cx23885_suspend(device_t dev)
    return error;
 }
 
-static devclass_t cx23885_devclass; 
-
 /* DEVMETHODs */
 static device_method_t cx23885_methods[] = 
 {
@@ -532,8 +530,13 @@ static driver_t cx23885_driver =
    0
 };
 
+#if __FreeBSD_version >= 1400058
+DRIVER_MODULE_ORDERED(cx23885b, pci, cx23885_driver, NULL, NULL, SI_ORDER_ANY);
+#else
+static devclass_t cx23885_devclass; 
+
 DRIVER_MODULE_ORDERED(cx23885b, pci, cx23885_driver, cx23885_devclass, NULL, NULL, SI_ORDER_ANY);
-DRIVER_MODULE_ORDERED(cx23885b, cardbus, cx23885_driver, cx23885_devclass, NULL, NULL, SI_ORDER_ANY);
+#endif
 
 CX88_DRIVER_MODULE(cx23885b);
 CX88_PCM_DRIVER_MODULE(cx23885b);
@@ -544,8 +547,6 @@ MODULE_VERSION(cx23885b, CX23885_MODVER);
 MODULE_DEPEND(cx23885b, cx23885adc, CX23885ADC_MINVER, CX23885ADC_MODVER, CX23885ADC_MAXVER);
 MODULE_VERSION(cx23885b, CX23885_MODVER);
 
-static devclass_t cx23885_i2c_devclass;
-
 static int cx23885_i2c_probe(device_t dev)
 {
    device_set_desc(dev, "CX23885/7/8 I2C master");
@@ -596,7 +597,13 @@ static driver_t cx23885_i2c_driver =
    sizeof(cx88_i2c_softc)
 };
 
+#if __FreeBSD_version >= 1400058
+DRIVER_MODULE(cx23885i2c, cx23885b, cx23885_i2c_driver, NULL, NULL);
+#else
+static devclass_t cx23885_i2c_devclass;
+
 DRIVER_MODULE(cx23885i2c, cx23885b, cx23885_i2c_driver, cx23885_i2c_devclass, NULL, NULL);
+#endif
 MODULE_DEPEND(cx23885i2c, cx23885b, CX23885_MINVER, CX23885_MODVER, CX23885_MAXVER);
 CX88_I2C_DRIVER_MODULE(cx23885i2c);
 MODULE_VERSION(cx23885i2c, 1);
