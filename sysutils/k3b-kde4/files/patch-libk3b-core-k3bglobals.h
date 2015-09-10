--- libk3b/core/k3bglobals.h.orig	2014-11-04 18:37:31 UTC
+++ libk3b/core/k3bglobals.h
@@ -231,6 +231,7 @@ namespace K3b {
      * Takes care of SCSI and ATAPI.
      */
     LIBK3B_EXPORT QString externalBinDeviceParameter( Device::Device* dev, const ExternalBin* );
+    LIBK3B_EXPORT QString externalBinGenericDeviceParameter( Device::Device* dev, const ExternalBin* );
 
     /**
      * Tries to convert urls from local protocols != "file" to file (for now supports media:/)
