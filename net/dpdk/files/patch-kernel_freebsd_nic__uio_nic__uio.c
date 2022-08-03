--- kernel/freebsd/nic_uio/nic_uio.c.orig	2022-07-26 18:39:52 UTC
+++ kernel/freebsd/nic_uio/nic_uio.c
@@ -78,10 +78,14 @@ struct pci_bdf {
 	uint32_t function;
 };
 
+DEFINE_CLASS_0(nic_uio, nic_uio_driver, nic_uio_methods, sizeof(struct nic_uio_softc));
+#if __FreeBSD_version >= 1400058
+DRIVER_MODULE(nic_uio, pci, nic_uio_driver, nic_uio_modevent, NULL);
+#else
 static devclass_t nic_uio_devclass;
 
-DEFINE_CLASS_0(nic_uio, nic_uio_driver, nic_uio_methods, sizeof(struct nic_uio_softc));
 DRIVER_MODULE(nic_uio, pci, nic_uio_driver, nic_uio_devclass, nic_uio_modevent, 0);
+#endif
 
 static int
 nic_uio_mmap(struct cdev *cdev, vm_ooffset_t offset, vm_paddr_t *paddr,
