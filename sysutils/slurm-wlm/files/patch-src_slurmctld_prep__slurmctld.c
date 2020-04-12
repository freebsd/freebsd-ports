--- src/slurmctld/prep_slurmctld.c.orig	2020-04-02 16:23:16 UTC
+++ src/slurmctld/prep_slurmctld.c
@@ -35,6 +35,7 @@
  *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA.
 \*****************************************************************************/
 
+#include <signal.h>
 #include "src/slurmctld/job_scheduler.h"
 #include "src/slurmctld/locks.h"
 #include "src/slurmctld/power_save.h"
