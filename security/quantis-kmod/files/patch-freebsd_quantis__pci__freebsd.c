--- freebsd/quantis_pci_freebsd.c.orig	2017-07-20 14:51:35 UTC
+++ freebsd/quantis_pci_freebsd.c
@@ -147,8 +147,6 @@ static struct cdevsw quantis_cdevsw = 
   .d_name =  "quantis",
 };
 
-static devclass_t quantis_devclass;
-
 /** Keep track of the numbers of card we manage for the corresponding
  ** IOCTL call. I guess this is already managed in some `device_t'
  ** structure.
@@ -200,7 +198,13 @@ static int quantis_load(struct module *module, int cmd
 }
 
 
+#if __FreeBSD_version >= 1400058
+DRIVER_MODULE(quantis, pci, quantis_pci_driver, quantis_load, NULL);
+#else
+static devclass_t quantis_devclass;
+
 DRIVER_MODULE(quantis, pci, quantis_pci_driver, quantis_devclass, quantis_load, 0);
+#endif
 
 
 static int quantis_pci_probe(device_t dev)
@@ -287,7 +291,6 @@ static int quantis_allocate_resources(device_t device)
  **/
 static int quantis_allocate_resources(device_t device)
 {
-  int  error;
   struct quantis_pci_device *scp = DEVICE2SOFTC(device);
 
   mtx_init(&scp->mutex, "Quantis Device Mutex", NULL, MTX_DEF);
@@ -301,7 +304,6 @@ errexit:
   return (0);
 
 errexit:
-  error = ENXIO;
   quantis_deallocate_resources(device);
   return (ENXIO);
 }
