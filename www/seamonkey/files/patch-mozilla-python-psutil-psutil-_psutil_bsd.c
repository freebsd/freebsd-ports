--- mozilla/python/psutil/psutil/_psutil_bsd.c.orig	2012-08-16 23:07:37.000000000 +0800
+++ mozilla/python/psutil/psutil/_psutil_bsd.c	2012-09-27 14:50:20.843763756 +0800
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
