--- os_freebsd.cpp.orig	2017-04-24 09:34:16.000000000 -0700
+++ os_freebsd.cpp	2018-02-22 23:01:44.118712000 -0800
@@ -15,6 +15,7 @@
  *
  */
 
+#include <sys/param.h>
 #include <stdio.h>
 #include <sys/types.h>
 #include <dirent.h>
@@ -484,7 +485,7 @@
   	}
   	nsid = 0xFFFFFFFF; // broadcast id
   }
-  else if (sscanf(dev, NVME_CTRLR_PREFIX"%d"NVME_NS_PREFIX"%d%c", 
+  else if (sscanf(dev, NVME_CTRLR_PREFIX"%d" NVME_NS_PREFIX "%d%c", 
   	&ctrlid, &nsid, &tmp) == 2) 
   {
   	if(ctrlid < 0 || nsid < 0) {
@@ -521,7 +522,11 @@
   struct nvme_pt_command pt;
   memset(&pt, 0, sizeof(pt));
 
-  pt.cmd.opc = in.opcode;
+#if __FreeBSD_version >= 1200058
+  pt.cmd.opc_fuse = NVME_CMD_SET_OPC(in.opcode);
+#else
+  pt.cmd.opc = in.opcode;
+#endif
   pt.cmd.nsid = in.nsid;
   pt.buf = in.buffer;
   pt.len = in.size;
