--- src/interfaces/cgroup.c.orig	2024-05-21 17:19:51 UTC
+++ src/interfaces/cgroup.c
@@ -421,6 +421,7 @@ extern char *autodetect_cgroup_version(void)
 	struct statfs fs;
 	int cgroup_ver = -1;
 
+#ifndef __FreeBSD__
 	if (statfs("/sys/fs/cgroup/", &fs) < 0) {
 		error("cgroup filesystem not mounted in /sys/fs/cgroup/");
 		return NULL;
@@ -453,6 +454,7 @@ extern char *autodetect_cgroup_version(void)
 		error("Unknown filesystem type mounted on /sys/fs/cgroup");
 		return NULL;
 	}
+#endif
 
 	log_flag(CGROUP, "%s: using cgroup version %d", __func__, cgroup_ver);
 
