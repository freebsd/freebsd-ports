--- os_freebsd.cpp.orig	2017-04-24 16:34:16 UTC
+++ os_freebsd.cpp
@@ -484,7 +484,7 @@ bool freebsd_nvme_device::open()
   	}
   	nsid = 0xFFFFFFFF; // broadcast id
   }
-  else if (sscanf(dev, NVME_CTRLR_PREFIX"%d"NVME_NS_PREFIX"%d%c", 
+  else if (sscanf(dev, NVME_CTRLR_PREFIX"%d" NVME_NS_PREFIX "%d%c", 
   	&ctrlid, &nsid, &tmp) == 2) 
   {
   	if(ctrlid < 0 || nsid < 0) {
