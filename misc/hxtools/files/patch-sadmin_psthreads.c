--- sadmin/psthreads.c.orig	2020-07-12 09:44:16 UTC
+++ sadmin/psthreads.c
@@ -141,15 +141,15 @@ static struct kps_proc_data *kps_proc_read_one(unsigne
 	HXlist_init(&task->process_children);
 	task->cmdlen = 0;
 
-	snprintf(buf, sizeof(buf), "/proc/%u/cmdline", pid);
+	snprintf(buf, sizeof(buf), "/compat/linux/proc/%u/cmdline", pid);
 	if ((fd = open(buf, O_RDONLY)) >= 0)
 		kps_read_cmdline(task, fd);
 
-	snprintf(buf, sizeof(buf), "/proc/%u/status", pid);
+	snprintf(buf, sizeof(buf), "/compat/linux/proc/%u/status", pid);
 	if ((fp = fopen(buf, "r")) != NULL)
 		kps_read_status(task, fp);
 
-	snprintf(buf, sizeof(buf), "/proc/%u/stat", pid);
+	snprintf(buf, sizeof(buf), "/compat/linux/proc/%u/stat", pid);
 	if ((fp = fopen(buf, "r")) != NULL)
 		kps_read_stat(task, fp);
 
@@ -162,8 +162,8 @@ static void kps_proc_read(struct HXmap *tree)
 	char buf[64];
 	struct HXdir *dproc, *dthr;
 
-	if ((dproc = HXdir_open("/proc")) == NULL) {
-		fprintf(stderr, "Could not open /proc: %s\n", strerror(errno));
+	if ((dproc = HXdir_open("/compat/linux/proc")) == NULL) {
+		fprintf(stderr, "Could not open /compat/linux/proc: %s\n", strerror(errno));
 		return;
 	}
 
@@ -175,7 +175,7 @@ static void kps_proc_read(struct HXmap *tree)
 		if (end == dentry || *end != '\0')
 			continue;
 
-		snprintf(buf, sizeof(buf), "/proc/%u/task", tgid);
+		snprintf(buf, sizeof(buf), "/compat/linux/proc/%u/task", tgid);
 		if ((dthr = HXdir_open(buf)) == NULL) {
 			fprintf(stderr, "Could not open %s: %s\n", buf, strerror(errno));
 			continue;
