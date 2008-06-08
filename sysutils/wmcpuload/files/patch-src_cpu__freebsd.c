--- src/cpu_freebsd.c.orig	2008-05-03 07:05:31.000000000 +0200
+++ src/cpu_freebsd.c	2008-05-03 07:12:09.000000000 +0200
@@ -18,7 +18,8 @@
 #include <string.h>
 #include "cpu.h"
 
-#include <kvm.h>
+#include <sys/sysctl.h>
+#include <sys/types.h>
 #include <fcntl.h>
 
 #include <sys/param.h>
@@ -29,24 +30,18 @@
 #   include <sys/resource.h>
 #endif /* __FreeBSD_version < 500101 */
 
-static kvm_t *kd = NULL;
-static struct nlist nlst[] = { {"_cp_time"}, {0} };
+static int sysctl_mib[2] = { -1, -1 };
+static size_t sysctl_len;
 
 void
 cpu_init(void)
 {
 
-    kd = kvm_open(NULL, NULL, NULL, O_RDONLY, "kvm_open");
+    sysctl_len = 2;
+    sysctlnametomib("kern.cp_time", sysctl_mib, &sysctl_len);
 
-    if (kd == NULL) {
-	fprintf(stderr, "can't open kernel virtual memory");
-	exit(1);
-    }
-
-    kvm_nlist(kd, nlst);
-
-    if (nlst[0].n_type == 0) {
-	fprintf(stderr, "error extracting symbols");
+    if (sysctl_mib[0] == -1) {
+	fprintf(stderr, "unknown sysctl kern.cp_time");
 	exit(1);
     }
 
@@ -68,14 +63,14 @@
     int used, total, result;
     unsigned long int cpu_time[CPUSTATES];
 
-    if (kvm_read(kd, nlst[0].n_value, &cpu_time, sizeof(cpu_time)) !=
-	sizeof(cpu_time))
-	return 0;
+    sysctl_len = sizeof(cpu_time);
+    if (sysctl(sysctl_mib, 2, &cpu_time, &sysctl_len, NULL, 0) == -1)
+	 return 0;
 
     used = cpu_time[CP_USER] + cpu_time[CP_SYS];
     if (!opts->ignore_nice)
 	used += cpu_time[CP_NICE];
-    total = used + cpu_time[CP_IDLE];
+    total = used + cpu_time[CP_IDLE] + cpu_time[CP_NICE];
 
     if (pre_total == 0) {
 	result = 0;
