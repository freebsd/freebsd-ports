--- programs/Xserver/hw/xfree86/drivers/mga/mga_driver.c.orig	Wed Jan 29 11:29:49 2003
+++ programs/Xserver/hw/xfree86/drivers/mga/mga_driver.c	Thu Mar 13 00:12:12 2003
@@ -304,7 +304,10 @@
     "drmAgpVendorId",
     "drmCommandNone",
     "drmCommandWrite",
+    "drmCtlInstHandler",
+    "drmCtlUninstHandler",
     "drmFreeVersion",
+    "drmGetInterruptFromBusID",
     "drmGetLibVersion",
     "drmGetVersion",
     "drmMap",
