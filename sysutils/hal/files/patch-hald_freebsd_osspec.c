--- hald/freebsd/osspec.c.orig	2008-05-07 19:24:01.000000000 -0400
+++ hald/freebsd/osspec.c	2009-02-18 00:24:42.000000000 -0500
@@ -46,6 +46,9 @@
 #include "hf-sound.h"
 #include "hf-storage.h"
 #include "hf-usb.h"
+#ifdef HAVE_LIBUSB20
+#include "hf-usb2.h"
+#endif
 #include "hf-volume.h"
 
 /* the order matters: PCI devices must be created before their children, etc */
@@ -53,6 +56,9 @@ static HFHandler *handlers[] = {
   &hf_pci_handler,
   &hf_devtree_handler,
   &hf_usb_handler,
+#ifdef HAVE_LIBUSB20
+  &hf_usb2_handler,
+#endif
   &hf_ata_handler,
   &hf_scsi_handler,
   &hf_storage_handler,
