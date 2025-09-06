--- src/plugins/task/pgid/task_pgid.c.orig     2025-09-03 23:58:57 UTC
+++ src/plugins/task/pgid/task_pgid.c
@@ -0,0 +1,152 @@
+#include "slurm_xlator.h"
+#include "log.h"
+#include "xmalloc.h"
+#include "task.h"   /* interface declarations */
+
+/* these two pull in batch_job_launch_msg_t, launch_tasks_request_msg_t,
+   stepd_step_task_info_t, etc. */
+#include "src/common/slurm_protocol_api.h"
+#include "src/slurmd/slurmstepd/slurmstepd_job.h"
+
+#include <sys/types.h>
+#include <signal.h>
+#include <unistd.h>
+#include <errno.h>
+#include <string.h>
+
+/* Required plugin identifiers (exported) */
+__attribute__((visibility("default"))) const char     plugin_name[]    = "PGID task plugin for FreeBSD";
+__attribute__((visibility("default"))) const char     plugin_type[]    = "task/pgid";
+__attribute__((visibility("default"))) const uint32_t plugin_version   = SLURM_VERSION_NUMBER;
+
+/* Required generic plugin entry points */
+int init(void)  { slurm_info("task/pgid: init");  return SLURM_SUCCESS; }
+int fini(void)  { slurm_info("task/pgid: fini");  return SLURM_SUCCESS; }
+
+static pid_t job_pgid = -1;
+
+/* ==== Required task_* API (must all be present) ==== */
+
+/* Called when slurmd receives a batch launch request */
+int task_p_slurmd_batch_request(batch_job_launch_msg_t *req)
+{
+    (void)req;
+    return SLURM_SUCCESS;
+}
+
+/* Called when slurmd receives a general launch request */
+int task_p_slurmd_launch_request(launch_tasks_request_msg_t *req,
+                                 uint32_t node_id, char **err_msg)
+{
+    (void)req; (void)node_id; (void)err_msg;
+    return SLURM_SUCCESS;
+}
+
+int task_p_slurmd_suspend_job(uint32_t job_id)
+{
+    (void)job_id;
+    return SLURM_SUCCESS;
+}
+
+int task_p_slurmd_resume_job(uint32_t job_id)
+{
+    (void)job_id;
+    return SLURM_SUCCESS;
+}
+
+/* Before setuid to the job user */
+int task_p_pre_setuid(stepd_step_rec_t *step)
+{
+    (void)step;
+    return SLURM_SUCCESS;
+}
+
+/* Called in privileged context before launch */
+int task_p_pre_launch_priv(stepd_step_rec_t *step,
+                           uint32_t node_tid, uint32_t global_tid)
+{
+    (void)step; (void)node_tid; (void)global_tid;
+    return SLURM_SUCCESS;
+}
+
+int task_p_pre_launch(stepd_step_rec_t *step)
+{
+    pid_t cur = getpid();
+
+    /* Case A: no PGID recorded yet for this step -> become the group leader */
+    if (step->pgid <= 0) {
+        if (setpgid(0, 0) < 0) {
+            /* If a sibling beat us to it, join that PGID instead */
+            if (errno == EACCES || errno == EPERM || errno == EEXIST) {
+                /* Someone created a group already; query our pgid and store it */
+                pid_t pg = getpgid(0);
+                if (pg < 0) {
+                    slurm_error("task/pgid: getpgid failed after race: %s", strerror(errno));
+                    return SLURM_ERROR;
+                }
+                step->pgid = pg;
+                slurm_debug("task/pgid: joined existing PGID %d (race)", step->pgid);
+                return SLURM_SUCCESS;
+            }
+            slurm_error("task/pgid: setpgid(0,0) failed for leader pid=%d: %s", (int)cur, strerror(errno));
+            return SLURM_ERROR;
+        }
+        step->pgid = getpgid(0);
+        if (step->pgid < 0) {
+            slurm_error("task/pgid: getpgid failed after creating group: %s", strerror(errno));
+            return SLURM_ERROR;
+        }
+        slurm_debug("task/pgid: created step PGID %d (leader pid=%d)", step->pgid, (int)cur);
+        return SLURM_SUCCESS;
+    }
+
+    /* Case B: PGID exists -> join it */
+    if (setpgid(0, step->pgid) < 0) {
+        /* ESRCH: parent/leader not visible yet; tiny retry helps on fast forks */
+        if (errno == ESRCH) {
+            usleep(1000); /* 1 ms backoff */
+            if (setpgid(0, step->pgid) == 0) {
+                slurm_debug("task/pgid: joined PGID %d after retry", step->pgid);
+                return SLURM_SUCCESS;
+            }
+        }
+        slurm_error("task/pgid: setpgid(0,%d) failed: %s", step->pgid, strerror(errno));
+        return SLURM_ERROR;
+    }
+    slurm_debug("task/pgid: joined existing PGID %d", step->pgid);
+    return SLURM_SUCCESS;
+}
+
+/* After a task terminates */
+int task_p_post_term(stepd_step_rec_t *step, stepd_step_task_info_t *task)
+{
+    (void)step; (void)task;
+    return SLURM_SUCCESS;
+}
+
+/* After the whole step finishes */
+int task_p_post_step(stepd_step_rec_t *step)
+{
+    (void)step;
+    return SLURM_SUCCESS;
+}
+
+/* Allow plugin to track additional PIDs if needed */
+int task_p_add_pid(pid_t pid)
+{
+    (void)pid;
+    return SLURM_SUCCESS;
+}
+
+int task_p_signal(stepd_step_rec_t *step, int sig)
+{
+    if (step && step->pgid > 1) {
+        slurm_debug("task/pgid: sending signal %d to PGID %d", sig, step->pgid);
+        if (killpg((pid_t)step->pgid, sig) < 0) {
+            slurm_error("task/pgid: killpg(%d) failed: %s", step->pgid, strerror(errno));
+            return SLURM_ERROR;
+        }
+    }
+    return SLURM_SUCCESS;
+}
+int task_p_fini(stepd_step_rec_t *step) { (void)step; return SLURM_SUCCESS; }
