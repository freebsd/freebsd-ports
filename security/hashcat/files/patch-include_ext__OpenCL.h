--- include/ext_OpenCL.h.orig	2016-06-28 09:47:32 UTC
+++ include/ext_OpenCL.h
@@ -27,6 +27,10 @@
 // #include <CL/cl_ext.h> // used for CL_DEVICE_TOPOLOGY_AMD but broken for dual GPU
 #endif
 
+#ifdef __FreeBSD__
+#include <CL/cl.h>
+#endif
+
 #include <shared.h>
 
 typedef cl_mem (CL_API_CALL *OCL_CLCREATEBUFFER)                 (cl_context, cl_mem_flags, size_t, void *, cl_int *);
