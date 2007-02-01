--- ./src/os/linux/OsProcessIteratorLinux.cpp.orig	Wed Jan  3 17:16:44 2007
+++ ./src/os/linux/OsProcessIteratorLinux.cpp	Wed Jan  3 20:45:43 2007
@@ -9,6 +9,16 @@
 #include <assert.h>
 #include <stdlib.h>
 
+#if defined(__FreeBSD__)
+#include <fcntl.h>
+#include <kvm.h>
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#include <sys/user.h>
+#include <limits.h>
+#include <paths.h>
+#endif
+
 // APPLICATION INCLUDES
 #include "os/OsFS.h"
 #include "os/linux/OsProcessIteratorLinux.h"
@@ -100,6 +110,7 @@
 
 /* //////////////////////////// PRIVATE /////////////////////////////////// */
 
+#if !defined(__FreeBSD__)
 //reads the status file in the /proc/nnnn directory
 OsStatus OsProcessIteratorLinux::readProcFile(OsPath &procDirname, OsProcess & rProcess)
 {
@@ -165,5 +176,43 @@
 
     return retval;
 }
+#else
+/*
+ * We need to do this differently under FreeBSD.  We could open the
+ * appropriate /proc/nnnn/status file as shown above, but OsFile
+ * wants to call fcntl() to lock the file when it is opened.  FreeBSD
+ * does not allow locking the procfs file and fails the fcntl() call.
+ * This in turn means we don't get to read the PID information and
+ * all sorts of bad things start happening.
+ *
+ * Rather than try to find a way to bypass the fcntl() call in some
+ * cases, let's just go ahead and use another method to get this PID
+ * information.
+ */
+OsStatus OsProcessIteratorLinux::readProcFile(OsPath &procDirname, OsProcess & rProcess)
+{
+    OsStatus retval = OS_FAILED;
+    kvm_t *kd;
+    struct kinfo_proc *kp;
+    int nentries, pid;
+    char errbuf[_POSIX2_LINE_MAX];
+
+    kd = kvm_openfiles(_PATH_DEVNULL, _PATH_DEVNULL, NULL, O_RDONLY, errbuf);
+    if (kd != NULL) {
+        nentries = -1;
+        pid = atoi(procDirname.data());
+        kp = kvm_getprocs(kd, KERN_PROC_PID, pid, &nentries);
+        if (kp != NULL && nentries > 0) {
+            rProcess.mProcessName = kp->ki_comm;
+            rProcess.mPID = kp->ki_pid;
+            rProcess.mParentPID = kp->ki_ppid;
+            retval = OS_SUCCESS;
+        }
+        kvm_close(kd);
+    }
+
+    return retval;
+}
+#endif
 
 /* ============================ FUNCTIONS ================================= */
