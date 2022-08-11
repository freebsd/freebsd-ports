--- if_ixl.c.orig	2022-05-13 22:17:15 UTC
+++ if_ixl.c
@@ -142,8 +142,12 @@ static driver_t ixl_driver = {
 	"ixl", ixl_methods, sizeof(struct ixl_pf),
 };
 
+#if __FreeBSD_version >= 1400058
+DRIVER_MODULE(ixl, pci, ixl_driver, 0, 0);
+#else
 devclass_t ixl_devclass;
 DRIVER_MODULE(ixl, pci, ixl_driver, ixl_devclass, 0, 0);
+#endif
 
 MODULE_VERSION(ixl, 2);
 
