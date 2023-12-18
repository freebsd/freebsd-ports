--- src/plugins/jobacct_gather/common/common_jag.c.orig	2023-11-21 22:33:29 UTC
+++ src/plugins/jobacct_gather/common/common_jag.c
@@ -233,7 +233,7 @@ static int _get_sys_interface_freq_line(uint32_t cpu, 
 	} else {
 		/* frequency scaling not enabled */
 		if (!cpunfo_frequency) {
-			snprintf(freq_file, 14, "/proc/cpuinfo");
+			snprintf(freq_file, 14, "/compat/linux/proc/cpuinfo");
 			log_flag(JAG, "filename = %s (cpu scaling not enabled)",
 			       freq_file);
 			if ((sys_fp = fopen(freq_file, "r")) != NULL) {
@@ -250,6 +250,11 @@ static int _get_sys_interface_freq_line(uint32_t cpu, 
 	return 0;
 }
 
+/*
+ * Check for lightweight processes (POSIX threads)
+ * Should be rewritten for FreeBSD so it doesn't depend on /proc
+ */
+
 static int _is_a_lwp(uint32_t pid)
 {
 	char *filename = NULL;
@@ -259,8 +264,12 @@ static int _is_a_lwp(uint32_t pid)
 	char *tgids = NULL;
 	pid_t tgid = -1;
 
-	xstrfmtcat(filename, "/proc/%u/status", pid);
+	// Disable check for now, this will only skew process accounting
+	// slightly by including threads
+	return 0;
 
+	xstrfmtcat(filename, "/compat/linux/proc/%u/status", pid);
+
 	fd = open(filename, O_RDONLY);
 	if (fd < 0) {
 		xfree(filename);
@@ -503,7 +512,7 @@ void _set_smaps_file(char **proc_smaps_file, pid_t pid
 	static int use_smaps_rollup = -1;
 
 	if (use_smaps_rollup == -1) {
-		xstrfmtcat(*proc_smaps_file, "/proc/%d/smaps_rollup", pid);
+		xstrfmtcat(*proc_smaps_file, "/compat/linux/proc/%d/smaps_rollup", pid);
 		FILE *fd = fopen(*proc_smaps_file, "r");
 		if (fd) {
 			fclose(fd);
@@ -514,9 +523,9 @@ void _set_smaps_file(char **proc_smaps_file, pid_t pid
 	}
 
 	if (use_smaps_rollup)
-		xstrfmtcat(*proc_smaps_file, "/proc/%d/smaps_rollup", pid);
+		xstrfmtcat(*proc_smaps_file, "/compat/linux/proc/%d/smaps_rollup", pid);
 	else
-		xstrfmtcat(*proc_smaps_file, "/proc/%d/smaps", pid);
+		xstrfmtcat(*proc_smaps_file, "/compat/linux/proc/%d/smaps", pid);
 }
 
 static void _handle_stats(pid_t pid, jag_callbacks_t *callbacks, int tres_count)
@@ -551,7 +560,7 @@ static void _handle_stats(pid_t pid, jag_callbacks_t *
 			disable_gpu_acct = 0;
 	}
 
-	xstrfmtcat(proc_file, "/proc/%u/stat", pid);
+	xstrfmtcat(proc_file, "/compat/linux/proc/%u/stat", pid);
 	if (!(stat_fp = fopen(proc_file, "r")))
 		return;  /* Assume the process went away */
 	/*
@@ -598,7 +607,7 @@ static void _handle_stats(pid_t pid, jag_callbacks_t *
 	/* Remove shared data from rss */
 	if (no_share_data) {
 		xfree(proc_file);
-		xstrfmtcat(proc_file, "/proc/%u/statm", pid);
+		xstrfmtcat(proc_file, "/compat/linux/proc/%u/statm", pid);
 		if (!_remove_share_data(proc_file, prec))
 			goto bail_out;
 	}
@@ -612,7 +621,7 @@ static void _handle_stats(pid_t pid, jag_callbacks_t *
 	}
 
 	xfree(proc_file);
-	xstrfmtcat(proc_file, "/proc/%u/io", pid);
+	xstrfmtcat(proc_file, "/compat/linux/proc/%u/io", pid);
 	if ((io_fp = fopen(proc_file, "r"))) {
 		fd2 = fileno(io_fp);
 		if (fcntl(fd2, F_SETFD, FD_CLOEXEC) == -1)
