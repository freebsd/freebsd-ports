--- aq_main.c.orig	2019-09-24 14:45:34 UTC
+++ aq_main.c
@@ -193,8 +193,12 @@ static driver_t aq_driver = {
 	"aq", aq_methods, sizeof(struct aq_dev),
 };
 
+#if __FreeBSD_version >= 1400058
+DRIVER_MODULE(atlantic, pci, aq_driver, 0, 0);
+#else
 static devclass_t aq_devclass;
 DRIVER_MODULE(atlantic, pci, aq_driver, aq_devclass, 0, 0);
+#endif
 
 MODULE_DEPEND(atlantic, pci, 1, 1, 1);
 MODULE_DEPEND(atlantic, ether, 1, 1, 1);
