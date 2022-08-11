--- iicdev/iicdev.c.orig	2022-07-26 16:18:50 UTC
+++ iicdev/iicdev.c
@@ -59,8 +59,6 @@ typedef struct
    struct sx lock;
 } iicdev_softc;
 
-static devclass_t iicdev_devclass;
-
 static int iicdev_probe(device_t dev);
 static int iicdev_attach(device_t dev);
 static int iicdev_detach(device_t dev);
@@ -233,7 +231,13 @@ static driver_t iicdev_driver =
    sizeof(iicdev_softc)
 };
 
+#if __FreeBSD_version >= 1400058
+DRIVER_MODULE(iicdev, iicbus, iicdev_driver, NULL, NULL);
+#else
+static devclass_t iicdev_devclass;
+
 DRIVER_MODULE(iicdev, iicbus, iicdev_driver, iicdev_devclass, NULL, NULL);
+#endif
 MODULE_DEPEND(iicdev, iicbus, IICBUS_MINVER, IICBUS_MODVER, IICBUS_MAXVER);
 MODULE_VERSION(iicdev, IICDEV_MODVER);
 
