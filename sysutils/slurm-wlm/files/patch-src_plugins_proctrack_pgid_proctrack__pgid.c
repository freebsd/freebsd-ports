--- src/plugins/proctrack/pgid/proctrack_pgid.c.orig	2020-03-26 21:44:05 UTC
+++ src/plugins/proctrack/pgid/proctrack_pgid.c
@@ -49,6 +49,15 @@
 #include <sys/types.h>
 #include <unistd.h>
 
+#ifdef __FreeBSD__
+#include <err.h>
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#include <sys/user.h>
+
+#include <libprocstat.h> /* must be last */
+#endif
+
 #include "slurm/slurm.h"
 #include "slurm/slurm_errno.h"
 #include "src/common/log.h"
@@ -179,6 +188,55 @@ proctrack_p_wait(uint64_t cont_id)
 	return SLURM_SUCCESS;
 }
 
+
+/*
+ * Get list of all PIDs belonging to process group cont_id
+ */
+#ifdef __FreeBSD__
+extern int proctrack_p_get_pids(uint64_t cont_id, pid_t **pids, int *npids)
+{
+	pid_t *pid_array = NULL;
+	struct procstat *proc_info;
+	struct kinfo_proc *proc_list;
+	FILE *procstat_err;
+	unsigned int pid_count = 0;
+
+	/*
+	 * procstat_getprocs() prints an innocuous but annoying warning
+	 * to stderr by default when no matching processes are found:
+	 *
+	 * https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=245318
+	 *
+	 * Remove the redirect to /dev/null if this changes in the future.
+	 */
+	if ((procstat_err = fopen("/dev/null", "w+")))
+		err_set_file(procstat_err);
+	proc_info = procstat_open_sysctl();
+	proc_list = procstat_getprocs(proc_info, KERN_PROC_PGRP, cont_id,
+				      (unsigned int *) &pid_count);
+	if (procstat_err)
+	{
+		err_set_file(NULL);
+		fclose(procstat_err);
+	}
+
+	if (pid_count > 0) {
+		xrecalloc(pid_array, sizeof(pid_t), pid_count);
+		// FIXME: Do we need to filter zombies like the Linux code?
+		// proc_list[c].ki_paddr->p_state == PRS_ZOMBIE
+		for (size_t c = 0; c < pid_count; ++c)
+			pid_array[c] = proc_list[c].ki_pid;
+	}
+
+	procstat_freeprocs(proc_info, proc_list);
+	procstat_close(proc_info);
+
+	*pids  = pid_array;
+	*npids = pid_count;
+
+	return SLURM_SUCCESS;
+}
+#else
 extern int
 proctrack_p_get_pids(uint64_t cont_id, pid_t **pids, int *npids)
 {
@@ -241,3 +299,4 @@ fini:	*pids  = pid_array;
 	*npids = pid_count;
 	return rc;
 }
+#endif
