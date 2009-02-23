--- hald/freebsd/hf-storage.h.orig	2009-02-23 01:43:49.000000000 -0500
+++ hald/freebsd/hf-storage.h	2009-02-23 01:45:17.000000000 -0500
@@ -29,8 +29,10 @@
 #endif
 
 #include "hf-osspec.h"
+#include "hf-devd.h"
 
 extern HFHandler hf_storage_handler;
+extern HFDevdHandler hf_storage_devd_handler;
 
 void hf_storage_device_enable (HalDevice *device);
 void hf_storage_device_enable_tape (HalDevice *device);
