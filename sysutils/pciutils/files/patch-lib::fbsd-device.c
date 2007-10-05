--- lib/fbsd-device.c.orig	Tue Jul 20 07:01:31 1999
+++ lib/fbsd-device.c	Tue Apr 12 10:49:09 2005
@@ -7,7 +7,9 @@
  *	Can be freely distributed and used under the terms of the GNU GPL.
  */
 
+#include <errno.h>
 #include <fcntl.h>
+#include <stdio.h>
 #include <string.h>
 #include <unistd.h>
 #include <osreldate.h>
@@ -19,13 +21,8 @@
 #  endif
 #endif
 
-#if __FreeBSD_version < 500000
-#  include <pci/pcivar.h>
-#else
-#  include <dev/pci/pcivar.h>
-#endif
-
 #if __FreeBSD_version < 430000
+#  include <pci/pcivar.h>
 #  include <pci/pci_ioctl.h>
 #else
 #  include <sys/pciio.h>
@@ -84,6 +81,9 @@
   if (pos >= 256)
     return 0;
 
+#if __FreeBSD_version >= 700053
+  pi.pi_sel.pc_domain = d->domain;
+#endif
   pi.pi_sel.pc_bus = d->bus;
   pi.pi_sel.pc_dev = d->dev;
   pi.pi_sel.pc_func = d->func;
@@ -92,7 +92,13 @@
   pi.pi_width = len;
 
   if (ioctl(d->access->fd, PCIOCREAD, &pi) < 0)
-    d->access->error("fbsd_read: ioctl(PCIOCREAD) failed");
+    {
+      if (errno == ENODEV)
+        {
+          return 0;
+        }
+      d->access->error("fbsd_read: ioctl(PCIOCREAD) failed: %s", strerror(errno));
+    }
 
   switch (len)
     {
@@ -100,10 +106,10 @@
       buf[0] = (u8) pi.pi_data;
       break;
     case 2:
-      ((u16 *) buf)[0] = (u16) pi.pi_data;
+      ((u16 *) buf)[0] = cpu_to_le16((u16) pi.pi_data);
       break;
     case 4:
-      ((u32 *) buf)[0] = (u32) pi.pi_data;
+      ((u32 *) buf)[0] = cpu_to_le32((u32) pi.pi_data);
       break;
     }
   return 1;
@@ -122,6 +128,9 @@
   if (pos >= 256)
     return 0;
 
+#if __FreeBSD_version >= 700053
+  pi.pi_sel.pc_domain = d->domain;
+#endif
   pi.pi_sel.pc_bus = d->bus;
   pi.pi_sel.pc_dev = d->dev;
   pi.pi_sel.pc_func = d->func;
@@ -135,16 +144,20 @@
       pi.pi_data = buf[0];
       break;
     case 2:
-      pi.pi_data = ((u16 *) buf)[0];
+      pi.pi_data = le16_to_cpu(((u16 *) buf)[0]);
       break;
     case 4:
-      pi.pi_data = ((u32 *) buf)[0];
+      pi.pi_data = le32_to_cpu(((u32 *) buf)[0]);
       break;
     }
 
   if (ioctl(d->access->fd, PCIOCWRITE, &pi) < 0)
     {
-      d->access->error("fbsd_write: ioctl(PCIOCWRITE) failed");
+      if (errno == ENODEV)
+        {
+          return 0;
+        }
+      d->access->error("fbsd_write: ioctl(PCIOCWRITE) failed: %s", strerror(errno));
     }
 
   return 1;
