--- src/interfaces/cgroup.c.orig	2023-11-21 22:33:29 UTC
+++ src/interfaces/cgroup.c
@@ -419,6 +419,7 @@ extern char *autodetect_cgroup_version(void)
 	struct statfs fs;
 	int cgroup_ver = -1;
 
+#ifndef __FreeBSD__
 	if (statfs("/sys/fs/cgroup/", &fs) < 0) {
 		error("cgroup filesystem not mounted in /sys/fs/cgroup/");
 		return NULL;
@@ -451,6 +452,7 @@ extern char *autodetect_cgroup_version(void)
 		error("Unknown filesystem type mounted on /sys/fs/cgroup");
 		return NULL;
 	}
+#endif
 
 	log_flag(CGROUP, "%s: using cgroup version %d", __func__, cgroup_ver);
 
