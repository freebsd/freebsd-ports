--- if_ixv.c.orig	2023-06-12 14:23:30 UTC
+++ if_ixv.c
@@ -146,8 +146,12 @@ static driver_t ixv_driver = {
 	"ixv", ixv_methods, sizeof(struct ixgbe_softc),
 };
 
+#if __FreeBSD_version >= 1400058
+DRIVER_MODULE(ixv, pci, ixv_driver, 0, 0);
+#else
 devclass_t ixv_devclass;
 DRIVER_MODULE(ixv, pci, ixv_driver, ixv_devclass, 0, 0);
+#endif
 MODULE_DEPEND(ixv, pci, 1, 1, 1);
 MODULE_DEPEND(ixv, ether, 1, 1, 1);
 #ifdef DEV_NETMAP
