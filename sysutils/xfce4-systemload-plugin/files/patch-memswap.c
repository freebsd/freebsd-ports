--- panel-plugin/memswap.c.orig	Tue Jul 29 21:40:55 2003
+++ panel-plugin/memswap.c	Thu Jul 31 22:43:10 2003
@@ -193,4 +193,113 @@
 
     return 0;
 }
-#endif
\ No newline at end of file
+#endif
+
+#if defined(__FreeBSD__)
+/*
+ * This is inspired by /usr/src/usr.bin/top/machine.c 
+ *
+ * Adapted by Thorsten Greiner <thorsten.greiner@web.de>
+ *
+ * Original authors: Christos Zoulas <christos@ee.cornell.edu>
+ *                   Steven Wallace  <swallace@freebsd.org>
+ *                   Wolfram Schneider <wosch@FreeBSD.org>
+ *                   Thomas Moestl <tmoestl@gmx.net>
+ */
+
+#include <sys/types.h>
+#include <fcntl.h>
+#include <kvm.h>
+
+#define GETSYSCTL(name, var) getsysctl(name, &(var), sizeof(var))
+
+static int getsysctl (char *name, void *ptr, size_t len)
+{
+    size_t nlen = len;
+    if (sysctlbyname(name, ptr, &nlen, NULL, 0) == -1) {
+        return -1;
+    }
+    if (nlen != len) {
+        return -1;
+    }
+    return 0;
+}
+
+static kvm_t *kd = NULL;
+
+static int swapmode(int *retavail, int *retfree)
+{
+    int n;
+    int pagesize = getpagesize();
+    struct kvm_swap swapary[1];
+    static int kd_init = TRUE;
+
+    if(kd_init) {
+        kd_init = FALSE;
+        if ((kd = kvm_open("/dev/null", "/dev/null", "/dev/null", 
+                           O_RDONLY, "kvm_open")) == NULL) {
+            g_warning("Cannot read kvm.");
+            return -1;
+        }
+    }
+    if(kd == NULL) {
+        return -1;
+    }
+
+    *retavail = 0;
+    *retfree = 0;
+
+#define CONVERT(v)	((quad_t)(v) * pagesize / 1024)
+
+    n = kvm_getswapinfo(kd, swapary, 1, 0);
+    if (n < 0 || swapary[0].ksw_total == 0)
+            return(0);
+
+    *retavail = CONVERT(swapary[0].ksw_total);
+    *retfree = CONVERT(swapary[0].ksw_total - swapary[0].ksw_used);
+
+    n = (int)((double)swapary[0].ksw_used * 100.0 /
+        (double)swapary[0].ksw_total);
+    return(n);
+}
+
+gint read_memswap(gulong *mem, gulong *swap, gulong *MT, gulong *MU, gulong *ST, gulong *SU)
+{
+    int total_pages;
+    int free_pages;
+    int inactive_pages;
+    int pagesize = getpagesize();
+    int swap_avail;
+    int swap_free;
+
+    if(GETSYSCTL("vm.stats.vm.v_page_count", total_pages)) {
+        g_warning("Cannot read sysctl \"vm.stats.vm.v_page_count\"");
+        return -1;
+    }
+    if(GETSYSCTL("vm.stats.vm.v_free_count", free_pages)) {
+        g_warning("Cannot read sysctl \"vm.stats.vm.v_free_count\"");
+        return -1;
+    }
+    if(GETSYSCTL("vm.stats.vm.v_inactive_count", inactive_pages)) {
+        g_warning("Cannot read sysctl \"vm.stats.vm.v_inactive_count\"");
+        return -1;
+    }
+
+    *MT = (total_pages*pagesize) >> 10;
+    *MU = ((total_pages-free_pages-inactive_pages) * pagesize) >> 10;
+    *mem = *MU * 100 / *MT;
+
+    if((*swap = swapmode(&swap_avail, &swap_free)) >= 0) {
+        *ST = swap_avail;
+        *SU = (swap_avail - swap_free);
+    }
+    else {
+        *swap = 0;
+        *ST = 0;
+        *SU = 0;
+    }
+
+    return 0;
+}
+
+#endif /* defined(__FREEBSD) */
