--- mbgclock/mbgclock_main.c.orig	2022-07-26 17:02:15 UTC
+++ mbgclock/mbgclock_main.c
@@ -585,7 +585,11 @@ static device_method_t mbgclock_methods[] =
 
 
 
+DEFINE_CLASS_0( mbgclock, mbgclock_driver, mbgclock_methods, sizeof( struct mbgclock_softc ) );
+#if __FreeBSD_version >= 1400058
+DRIVER_MODULE( mbgclock, pci, mbgclock_driver, 0, 0 );
+#else
 static devclass_t mbgclock_devclass;
 
-DEFINE_CLASS_0( mbgclock, mbgclock_driver, mbgclock_methods, sizeof( struct mbgclock_softc ) );
 DRIVER_MODULE( mbgclock, pci, mbgclock_driver, mbgclock_devclass, 0, 0 );
+#endif
