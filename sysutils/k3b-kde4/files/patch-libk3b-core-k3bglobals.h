--- libk3b/core/k3bglobals.h.orig	2010-07-30 06:40:13.000000000 +0200
+++ libk3b/core/k3bglobals.h	2010-07-30 06:41:05.000000000 +0200
@@ -230,6 +230,7 @@
      * Takes care of SCSI and ATAPI.
      */
     LIBK3B_EXPORT QString externalBinDeviceParameter( Device::Device* dev, const ExternalBin* );
+    LIBK3B_EXPORT QString externalBinGenericDeviceParameter( Device::Device* dev, const ExternalBin* );
 
     /**
      * Tries to convert urls from local protocols != "file" to file (for now supports media:/)
