--- psutil/_psutil_bsd.c.orig	2012-08-16 23:07:37.000000000 +0800
+++ psutil/_psutil_bsd.c	2012-09-27 14:50:20.843763756 +0800
@@ -576,12 +576,19 @@ get_process_memory_info(PyObject* self, 
 static PyObject*
 get_virtual_mem(PyObject* self, PyObject* args)
 {
-    unsigned int   total, active, inactive, wired, cached, free, buffers;
+    unsigned int   total, active, inactive, wired, cached, free;
     size_t		   size = sizeof(total);
 	struct vmtotal vm;
 	int            mib[] = {CTL_VM, VM_METER};
 	long           pagesize = getpagesize();
 
+#if __FreeBSD_version > 702101
+    long buffers;
+#else
+    int buffers;
+#endif
+    size_t buffers_size = sizeof(buffers);
+
     if (sysctlbyname("vm.stats.vm.v_page_count", &total, &size, NULL, 0))
         goto error;
     if (sysctlbyname("vm.stats.vm.v_active_count", &active, &size, NULL, 0))
@@ -594,7 +601,7 @@ get_virtual_mem(PyObject* self, PyObject
         goto error;
     if (sysctlbyname("vm.stats.vm.v_free_count", &free, &size, NULL, 0))
         goto error;
-    if (sysctlbyname("vfs.bufspace", &buffers, &size, NULL, 0))
+    if (sysctlbyname("vfs.bufspace", &buffers, &buffers_size, NULL, 0))
         goto error;
 
     size = sizeof(vm);
@@ -1376,8 +1376,10 @@
             strlcat(opts, ",noclusterr", sizeof(opts));
         if (flags & MNT_NOCLUSTERW)
             strlcat(opts, ",noclusterw", sizeof(opts));
+#if __FreeBSD_version >= 800000
         if (flags & MNT_NFS4ACLS)
             strlcat(opts, ",nfs4acls", sizeof(opts));
+#endif
 
         py_tuple = Py_BuildValue("(ssss)", fs[i].f_mntfromname,  // device
                                            fs[i].f_mntonname,    // mount point
