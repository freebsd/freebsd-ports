--- src/cpu_freebsd.c.orig	2016-10-20 13:55:48 UTC
+++ src/cpu_freebsd.c
@@ -16,7 +16,8 @@
 #include <string.h>
 #include "cpu.h"
 
-#include <kvm.h>
+#include <sys/sysctl.h>
+#include <sys/types.h>
 #include <fcntl.h>
 
 #include <sys/param.h>
@@ -27,27 +28,21 @@
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
+    if (sysctl_mib[0] == -1) {
+	fprintf(stderr, "unknown sysctl kern.cp_time");
 	exit(1);
     }
 
-    kvm_nlist(kd, nlst);
-
-    if (nlst[0].n_type == 0) {
-	fprintf(stderr, "error extracting symbols");
-	exit(1);
-    }
-
     /* drop setgid & setuid (the latter should not be there really) */
     seteuid(getuid());
     setegid(getgid());
@@ -66,8 +61,8 @@ cpu_get_usage(cpu_options *opts)
     int used, total, result;
     unsigned long int cpu_time[CPUSTATES];
 
-    if (kvm_read(kd, nlst[0].n_value, &cpu_time, sizeof(cpu_time)) !=
-	sizeof(cpu_time))
+    sysctl_len = sizeof(cpu_time);
+    if (sysctl(sysctl_mib, 2, &cpu_time, &sysctl_len, NULL, 0) == -1)
 	return 0;
 
     /* calculate usage */
