--- programs/Xserver/hw/xfree86/drivers/ati/r128_driver.c.orig	Sat Jan 11 05:45:34 2003
+++ programs/Xserver/hw/xfree86/drivers/ati/r128_driver.c	Sat Jan 11 05:45:41 2003
@@ -277,6 +277,7 @@
     "drmAgpUnbind",
     "drmAgpVendorId",
     "drmAvailable",
+    "drmFreeBufs",
     "drmFreeVersion",
     "drmGetVersion",
     "drmMap",
@@ -287,6 +288,7 @@
     "drmR128ResetCCE",
     "drmR128StartCCE",
     "drmR128StopCCE",
+    "drmR128TextureBlit",
     "drmR128WaitForIdleCCE",
     "drmR128FlushIndirectBuffer",
     "drmScatterGatherAlloc",
