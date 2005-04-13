--- lib/fbsd-device.c.orig	Tue Jul 20 07:01:31 1999
+++ lib/fbsd-device.c	Tue Apr 12 10:49:09 2005
@@ -13,10 +13,21 @@
 
 #include <fcntl.h>
 #include <string.h>
+#include <errno.h>
 #include <unistd.h>
+#include <osreldate.h>
 
-#include <pci/pcivar.h>
-#include <pci/pci_ioctl.h>
+#if __FreeBSD_version < 500000
+#  include <pci/pcivar.h>
+#else
+#  include <dev/pci/pcivar.h>
+#endif
+
+#if __FreeBSD_version < 430000
+#  include <pci/pci_ioctl.h>
+#else
+#  include <sys/pciio.h>
+#endif
 
 #include "internal.h"
 
@@ -75,8 +86,12 @@
   pi.pi_reg = pos;
   pi.pi_width = len;
 	
-  if (ioctl(d->access->fd, PCIOCREAD, &pi) < 0)
-    d->access->error("fbsd_read: ioctl(PCIOCREAD) failed");
+  if (ioctl(d->access->fd, PCIOCREAD, &pi) < 0) {
+    if (errno == ENODEV)
+      return 0;
+    else
+      d->access->error("fbsd_read: ioctl(PCIOCREAD) failed");
+  }
   
   switch (len)
     {
