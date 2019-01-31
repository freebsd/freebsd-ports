Index: os_freebsd.cpp
===================================================================
--- os_freebsd.cpp.orig	2018-12-05 18:30:46 UTC
+++ os_freebsd.cpp
@@ -9,6 +9,7 @@
  */
 
 #include <sys/param.h>
+#include <sys/endian.h>
 #include <stdio.h>
 #include <sys/types.h>
 #include <dirent.h>
@@ -522,29 +523,29 @@ bool freebsd_nvme_device::nvme_pass_through(const nvme
   pt.cmd.opc = in.opcode;
 #endif
   pt.cmd.opc = in.opcode;
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
 
   if (status < 0)
     return set_err(errno, "NVME_PASSTHROUGH_CMD: %s", strerror(errno));
-
+#if __FreeBSD_version >= 1200058
+  nvme_completion_swapbytes(&pt.cpl);
+#endif
   cp_p = &pt.cpl;
   out.result=cp_p->cdw0; // Command specific result (DW0)
 
   if (nvme_completion_is_error(cp_p)) {  /* ignore DNR and More bits */
-    uint16_t nvme_status = ((cp_p->status.sct << 8) | cp_p->status.sc) & 0x3ff;
-
-    return set_nvme_err(out, nvme_status);
+    return set_nvme_err(out, nvme_completion_is_error(&pt.cpl));
   }
 
   return true;
