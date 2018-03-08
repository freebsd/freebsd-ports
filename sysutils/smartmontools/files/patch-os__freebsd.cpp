--- os_freebsd.cpp.orig	2017-04-24 09:34:16.000000000 -0700
+++ os_freebsd.cpp	2018-02-27 19:15:54.338861000 +0000
@@ -16,6 +16,8 @@
  */
 
 #include <stdio.h>
+#include <sys/endian.h>
+#include <sys/param.h>
 #include <sys/types.h>
 #include <dirent.h>
 #include <fcntl.h>
@@ -484,7 +486,7 @@
   	}
   	nsid = 0xFFFFFFFF; // broadcast id
   }
-  else if (sscanf(dev, NVME_CTRLR_PREFIX"%d"NVME_NS_PREFIX"%d%c", 
+  else if (sscanf(dev, NVME_CTRLR_PREFIX"%d" NVME_NS_PREFIX "%d%c", 
   	&ctrlid, &nsid, &tmp) == 2) 
   {
   	if(ctrlid < 0 || nsid < 0) {
@@ -521,16 +523,20 @@
   struct nvme_pt_command pt;
   memset(&pt, 0, sizeof(pt));
 
+#if __FreeBSD_version >= 1200058
+  pt.cmd.opc_fuse = NVME_CMD_SET_OPC(in.opcode);
+#else
   pt.cmd.opc = in.opcode;
+#endif
-  pt.cmd.nsid = in.nsid;
+  pt.cmd.nsid = htole32(in.nsid);
   pt.buf = in.buffer;
   pt.len = in.size;
-  pt.cmd.cdw10 = in.cdw10;
-  pt.cmd.cdw11 = in.cdw11;
-  pt.cmd.cdw12 = in.cdw12;
-  pt.cmd.cdw13 = in.cdw13;
-  pt.cmd.cdw14 = in.cdw14;
-  pt.cmd.cdw15 = in.cdw15;
+  pt.cmd.cdw10 = htole32(in.cdw10);
+  pt.cmd.cdw11 = htole32(in.cdw11);
+  pt.cmd.cdw12 = htole32(in.cdw12);
+  pt.cmd.cdw13 = htole32(in.cdw13);
+  pt.cmd.cdw14 = htole32(in.cdw14);
+  pt.cmd.cdw15 = htole32(in.cdw15);
   pt.is_read = 1; // should we use in.direction()?
   
   int status = ioctl(get_fd(), NVME_PASSTHROUGH_CMD, &pt);
@@ -538,6 +544,9 @@
   if (status < 0)
     return set_err(errno, "NVME_PASSTHROUGH_CMD: %s", strerror(errno));
 
+#if __FreeBSD_version >= 1200058
+  nvme_completion_swapbytes(&pt.cpl);
+#endif
   out.result=pt.cpl.cdw0; // Command specific result (DW0)
 
   if (nvme_completion_is_error(&pt.cpl))
