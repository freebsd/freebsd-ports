--- if_iavf_iflib.c.orig	2023-07-06 09:26:54 UTC
+++ if_iavf_iflib.c
@@ -130,8 +130,12 @@ static driver_t iavf_driver = {
 	"iavf", iavf_methods, sizeof(struct iavf_sc),
 };
 
+#if __FreeBSD_version >= 1400058
+DRIVER_MODULE(iavf, pci, iavf_driver, 0, 0);
+#else
 devclass_t iavf_devclass;
 DRIVER_MODULE(iavf, pci, iavf_driver, iavf_devclass, 0, 0);
+#endif
 MODULE_VERSION(iavf, 1);
 
 MODULE_DEPEND(iavf, pci, 1, 1, 1);
