--- if_igb.c.orig	2023-06-12 15:16:16 UTC
+++ if_igb.c
@@ -252,8 +252,12 @@ static driver_t igb_driver = {
 	"igb", igb_methods, sizeof(struct adapter),
 };
 
+#if __FreeBSD_version >= 1400058
+DRIVER_MODULE(igb, pci, igb_driver, 0, 0);
+#else
 static devclass_t igb_devclass;
 DRIVER_MODULE(igb, pci, igb_driver, igb_devclass, 0, 0);
+#endif
 MODULE_DEPEND(igb, pci, 1, 1, 1);
 MODULE_DEPEND(igb, ether, 1, 1, 1);
 #ifdef DEV_NETMAP
