Obtained from:	https://github.com/giampaolo/psutil/commit/04794aa03cb9d30287e8e7fd9c80acc8c4f2aa46

--- psutil/arch/posix/sysctl.c.orig	2026-01-12 08:59:45 UTC
+++ psutil/arch/posix/sysctl.c
@@ -28,7 +28,7 @@ psutil_sysctl(int *mib, u_int miblen, void *buf, size_
         return -1;
     }
 
-    if (len != buflen) {
+    if (len > buflen) {
         psutil_runtime_error("sysctl() size mismatch");
         return -1;
     }
@@ -139,7 +139,7 @@ psutil_sysctlbyname(const char *name, void *buf, size_
         return -1;
     }
 
-    if (len != buflen) {
+    if (len > buflen) {
         str_format(
             errbuf,
             sizeof(errbuf),
