--- coda-src/venus/worker.cc.orig	2008-10-06 16:52:22 UTC
+++ coda-src/venus/worker.cc
@@ -397,17 +397,17 @@ void VFSMount()
 	    md[0].iov_base = (char *)"fstype"; md[0].iov_len = sizeof("fstype");
 	    md[1].iov_base = (char *)"coda";   md[1].iov_len = sizeof("coda");
 	    md[2].iov_base = (char *)"fspath"; md[2].iov_len = sizeof("fspath");
-	    md[3].iov_base = venusRoot;        md[3].iov_len = strlen(venusRoot) + 1;
+	    md[3].iov_base = (char *)venusRoot;        md[3].iov_len = strlen((char *)venusRoot) + 1;
 	    md[4].iov_base = (char *)"from";   md[4].iov_len = sizeof("from");
-	    md[5].iov_base = kernDevice;       md[5].iov_len = strlen(kernDevice) + 1;
+	    md[5].iov_base = (char *)kernDevice;       md[5].iov_len = strlen((char *)kernDevice) + 1;
 	    error = nmount(md, 6, 0);
 	}
 #endif
 			
 	if (error < 0)
-	    error = mount("coda", venusRoot, 0, kernDevice);
+	    error = mount("coda", (char *)venusRoot, 0, (char *)kernDevice);
 	if (error < 0)
-	    error = mount("cfs", venusRoot, 0, kernDevice);
+	    error = mount("cfs", (char *)venusRoot, 0, (char *)kernDevice);
 #if defined(__FreeBSD__) && !defined(__FreeBSD_version)
 #define MOUNT_CFS 19
 	if (error < 0)
