--- if_ix.c.orig	2022-05-13 22:10:39 UTC
+++ if_ix.c
@@ -241,8 +241,12 @@ static driver_t ix_driver = {
 	"ix", ix_methods, sizeof(struct adapter),
 };
 
+#if __FreeBSD_version >= 1400058
+DRIVER_MODULE(ix, pci, ix_driver, 0, 0);
+#else
 devclass_t ix_devclass;
 DRIVER_MODULE(ix, pci, ix_driver, ix_devclass, 0, 0);
+#endif
 
 MODULE_DEPEND(ix, pci, 1, 1, 1);
 MODULE_DEPEND(ix, ether, 1, 1, 1);
