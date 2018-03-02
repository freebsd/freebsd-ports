--- src/mod_cband.c.orig
+++ src/mod_cband.c
@@ -56,6 +56,9 @@
 #include <sys/types.h>
 #include <sys/ipc.h>
 #include <sys/sem.h>
+#ifdef __FreeBSD__
+#include <sys/param.h>
+#endif
 #include <unistd.h>
 
 #include "mod_cband.h"
@@ -74,6 +77,14 @@
 }
 #endif
 
+#if defined(__FreeBSD__) && __FreeBSD_version >= 1200059
+union semun {
+	int	val;		/* value for SETVAL */
+	struct	semid_ds *buf;	/* buffer for IPC_STAT & IPC_SET */
+	u_short *array;		/* array for GETALL & SETALL */
+};
+#endif
+
 static mod_cband_config_header *config = NULL;
 static const char mod_cband_filter_name[] = "CBAND_FILTER";
 ap_filter_rec_t *mod_cband_output_filter_handle;
