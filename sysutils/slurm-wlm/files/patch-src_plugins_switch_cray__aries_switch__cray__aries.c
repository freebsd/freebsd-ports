--- src/plugins/switch/cray_aries/switch_cray_aries.c.orig	2019-05-30 01:52:34 UTC
+++ src/plugins/switch/cray_aries/switch_cray_aries.c
@@ -35,7 +35,6 @@
  *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA.
 \*****************************************************************************/
 
-#if !(defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__))
 #include "config.h"
 
 #define _GNU_SOURCE
@@ -44,7 +43,9 @@
 #include <fcntl.h>
 #include <inttypes.h>
 #include <limits.h>
+#ifdef __linux__
 #include <linux/limits.h>
+#endif
 #include <math.h>
 #include <sched.h>
 #include <signal.h>
@@ -1078,4 +1079,3 @@ extern int switch_p_job_step_post_resume(stepd_step_re
 #endif
 	return SLURM_SUCCESS;
 }
-#endif /* !defined(__FreeBSD__) */
