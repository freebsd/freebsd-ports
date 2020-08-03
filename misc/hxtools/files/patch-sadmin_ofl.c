--- sadmin/ofl.c.orig	2020-07-12 09:44:16 UTC
+++ sadmin/ofl.c
@@ -42,7 +42,7 @@ static const char *ofl_comm(pid_t pid, char *buf, size
 	const char *p;
 	ssize_t ret;
 
-	snprintf(src, sizeof(src), "/proc/%u/exe", (unsigned int)pid);
+	snprintf(src, sizeof(src), "/compat/linux/proc/%u/exe", (unsigned int)pid);
 	ret = readlink(src, dst, sizeof(dst) - 1);
 	if (ret < 0) {
 		*buf = '\0';
@@ -227,7 +227,7 @@ static bool ofl(const char *mnt, unsigned int signum)
 	char tmp[256];
 	struct HXdir *dir;
 
-	dir = HXdir_open("/proc");
+	dir = HXdir_open("/compat/linux/proc");
 	if (dir == NULL)
 		return false;
 	while ((de = HXdir_read(dir)) != NULL) {
@@ -236,30 +236,30 @@ static bool ofl(const char *mnt, unsigned int signum)
 		data.pid = strtoul(de, NULL, 0);
 		if (data.pid == 0)
 			continue;
-		snprintf(tmp, sizeof(tmp), "/proc/%s", de);
+		snprintf(tmp, sizeof(tmp), "/compat/linux/proc/%s", de);
 		if (lstat(tmp, &data.sb) < 0 || !S_ISDIR(data.sb.st_mode))
 			continue;
 
 		/* Program map */
-		snprintf(tmp, sizeof(tmp), "/proc/%s/maps", de);
+		snprintf(tmp, sizeof(tmp), "/compat/linux/proc/%s/maps", de);
 		if (ofl_pmap(mnt, tmp, &data))
 			continue;
 
 		/* Basic links */
 		data.check = true;
-		snprintf(tmp, sizeof(tmp), "/proc/%s/root", de);
+		snprintf(tmp, sizeof(tmp), "/compat/linux/proc/%s/root", de);
 		if (ofl_one(mnt, tmp, &data))
 			continue;
-		snprintf(tmp, sizeof(tmp), "/proc/%s/cwd", de);
+		snprintf(tmp, sizeof(tmp), "/compat/linux/proc/%s/cwd", de);
 		if (ofl_one(mnt, tmp, &data))
 			continue;
-		snprintf(tmp, sizeof(tmp), "/proc/%s/exe", de);
+		snprintf(tmp, sizeof(tmp), "/compat/linux/proc/%s/exe", de);
 		if (ofl_one(mnt, tmp, &data))
 			continue;
 
 		/* All file descriptors */
 		data.check = false;
-		snprintf(tmp, sizeof(tmp), "/proc/%s/task", de);
+		snprintf(tmp, sizeof(tmp), "/compat/linux/proc/%s/task", de);
 		ofl_task(mnt, tmp, &data);
 	}
 
