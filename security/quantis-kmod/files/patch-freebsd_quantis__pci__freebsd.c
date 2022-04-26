--- freebsd/quantis_pci_freebsd.c.orig	2022-04-26 15:35:51 UTC
+++ freebsd/quantis_pci_freebsd.c
@@ -287,7 +287,6 @@ static int quantis_detach(device_t device, struct quan
  **/
 static int quantis_allocate_resources(device_t device)
 {
-  int  error;
   struct quantis_pci_device *scp = DEVICE2SOFTC(device);
 
   mtx_init(&scp->mutex, "Quantis Device Mutex", NULL, MTX_DEF);
@@ -301,7 +300,6 @@ static int quantis_allocate_resources(device_t device)
   return (0);
 
 errexit:
-  error = ENXIO;
   quantis_deallocate_resources(device);
   return (ENXIO);
 }
