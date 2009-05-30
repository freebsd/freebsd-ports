--- hald/freebsd/osspec.c.orig	2008-05-07 19:24:01.000000000 -0400
+++ hald/freebsd/osspec.c	2009-05-30 03:14:33.000000000 -0400
@@ -25,6 +25,7 @@
 #  include <config.h>
 #endif
 
+#include <sys/param.h>
 #include <string.h>
 
 #include "../ids.h"
@@ -46,13 +47,21 @@
 #include "hf-sound.h"
 #include "hf-storage.h"
 #include "hf-usb.h"
+#ifdef HAVE_LIBUSB20
+#include "hf-usb2.h"
+#endif
 #include "hf-volume.h"
 
 /* the order matters: PCI devices must be created before their children, etc */
 static HFHandler *handlers[] = {
   &hf_pci_handler,
   &hf_devtree_handler,
+#if __FreeBSD_version < 800092
   &hf_usb_handler,
+#endif
+#ifdef HAVE_LIBUSB20
+  &hf_usb2_handler,
+#endif
   &hf_ata_handler,
   &hf_scsi_handler,
   &hf_storage_handler,
