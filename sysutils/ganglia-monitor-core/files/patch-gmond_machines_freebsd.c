
$FreeBSD$

--- gmond/machines/freebsd.c.orig	Thu Aug 15 10:17:25 2002
+++ gmond/machines/freebsd.c	Wed May 28 12:51:18 2003
@@ -10,11 +10,36 @@
 #include <sys/param.h> 
 #include <sys/sysctl.h>
 #include <sys/user.h>
+#if __FreeBSD_version < 500101
 #include <sys/dkstat.h>
+#else
+#include <sys/resource.h>
+#endif
+#include <sys/stat.h>
+#include <vm/vm_param.h>
 #include <unistd.h>
 #include "ganglia.h"
 #include "metric_typedefs.h"
 
+#define MIB_SWAPINFO_SIZE 3
+
+#ifndef XSWDEV_VERSION
+#define XSWDEV_VERSION  1
+struct xswdev {
+        u_int   xsw_version;
+        udev_t  xsw_dev;
+        int     xsw_flags;
+        int     xsw_nblks;
+        int     xsw_used;
+};
+#endif
+
+static int use_vm_swap_info = 0;
+static int mibswap[MIB_SWAPINFO_SIZE];
+static size_t mibswap_size;
+static kvm_t *kd = NULL;
+static int pagesize;
+
 /* Function prototypes */
 long percentages(int cnt, int *out, register long *new,
                           register long *old, long *diffs);
@@ -27,6 +52,19 @@
 metric_init(void)
 {
    g_val_t val;
+
+   /*
+    * Try to use the vm.swap_info sysctl to gather swap data.  If it
+    * isn't implemented, fall back to trying to old kvm based interface.
+    */
+   mibswap_size = MIB_SWAPINFO_SIZE;
+   if (sysctlnametomib("vm.swap_info", mibswap, &mibswap_size) == -1) {
+      kd = kvm_open(NULL, NULL, NULL, O_RDONLY, "metric_init()"); 
+   } else {
+      use_vm_swap_info = 1;
+   }
+   pagesize = getpagesize();
+
    val.int32 = SYNAPSE_SUCCESS;
    return val;
 }
@@ -81,21 +119,33 @@
 swap_total_func ( void )
 {
    g_val_t val;
-
    struct kvm_swap swap[1];
-   kvm_t *kd;
+   struct xswdev xsw;
+   size_t mibsize, size;
    int totswap, n;
 
-   kd = kvm_open(NULL, NULL, NULL, O_RDONLY, "kvm_open"); 
-   n = kvm_getswapinfo(kd, swap, 1, 0);
-   if (n < 0 || swap[0].ksw_total == 0) { 
-       val.uint32 = 0;
+   val.uint32 = 0; 
+   totswap = 0;
+
+   if (use_vm_swap_info) {
+      for (n = 0; ; ++n) {
+	 mibswap[mibswap_size] = n;
+	 size = sizeof(xsw);
+	 if (sysctl(mibswap, mibswap_size + 1, &xsw, &size, NULL, NULL) == -1)
+	    break;
+	 if (xsw.xsw_version != XSWDEV_VERSION)
+	    return val;
+         totswap += xsw.xsw_nblks;
+       }
+   } else if(kd != NULL) {
+      n = kvm_getswapinfo(kd, swap, 1, 0);
+      if (n < 0 || swap[0].ksw_total == 0) { 
+         val.uint32 = 0;
+      }
+      totswap = swap[0].ksw_total;
    }
-   totswap = swap[0].ksw_total;
-   totswap *= getpagesize() / 1024;
-   val.uint32 = totswap;
-   kvm_close(kd);
 
+   val.uint32 = totswap * (pagesize / 1024);
    return val;
 }
 
@@ -330,9 +380,8 @@
    len = sizeof (free_pages);
    if((sysctlbyname("vm.stats.vm.v_free_count", &free_pages, &len, NULL, 0) 
 	== -1) || !len) free_pages = 0; 
-   free_pages *= getpagesize() / 1024;
 
-   val.uint32 = free_pages;
+   val.uint32 = free_pages * (pagesize / 1024);
    return val;
 }
 
@@ -373,9 +422,7 @@
 	|| !len)
       cache = 0; 
 
-   cache *= getpagesize() / 1024;
-
-   val.uint32 = cache;
+   val.uint32 = cache * (pagesize / 1024);
    return val;
 }
 
@@ -383,23 +430,35 @@
 swap_free_func ( void )
 {
    g_val_t val;
+
    struct kvm_swap swap[1];
-   kvm_t *kd;
+   struct xswdev xsw;
+   size_t size;
    int totswap, usedswap, freeswap, n;
 
-   kd = kvm_open(NULL, NULL, NULL, O_RDONLY, "kvm_open");
-   n = kvm_getswapinfo(kd, swap, 1, 0);
-   if (n < 0 || swap[0].ksw_total == 0) {
-       val.uint32 = 0;
-   }
-   totswap = swap[0].ksw_total;
-   usedswap = swap[0].ksw_used;
-   kvm_close(kd);
+   val.uint32 = 0;
+   totswap = 0;
+   usedswap = 0;
 
-   freeswap = totswap-usedswap;
-   freeswap *= getpagesize() / 1024;
+   if (use_vm_swap_info) {
+      for (n = 0; ; ++n) {
+	 mibswap[mibswap_size] = n;
+	 size = sizeof(xsw);
+	 if (sysctl(mibswap, mibswap_size + 1, &xsw, &size, NULL, NULL) == -1)
+	    break;
+	 if (xsw.xsw_version != XSWDEV_VERSION)
+	    return val;
+         totswap += xsw.xsw_nblks;
+         usedswap += xsw.xsw_used;
+       }
+   } else if(kd != NULL) { 
+      n = kvm_getswapinfo(kd, swap, 1, 0);
+      totswap = swap[0].ksw_total;
+      usedswap = swap[0].ksw_used;
+   }
+   freeswap = totswap - usedswap;
 
-   val.uint32 = freeswap;
+   val.uint32 = freeswap * (pagesize / 1024);
    return val;
 }
 
