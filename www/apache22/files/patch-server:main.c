--- server/main.c.orig	Thu Jun 13 04:34:56 2002
+++ server/main.c	Sun Jul 21 08:54:09 2002
@@ -78,6 +78,11 @@
 #include "ap_mpm.h"
 #include "mpm_common.h"
 
+#ifdef FREEBSD_THREAD_HACK
+#include <unistd.h>
+AP_DECLARE(int) ap_exists_config_define(const char *name);
+#endif
+
 /* WARNING: Win32 binds http_main.c dynamically to the server. Please place
  *          extern functions and global data in another appropriate module.
  *
@@ -558,6 +563,21 @@
         destroy_and_exit_process(process, 1);
     }
 
+#ifdef FREEBSD_THREAD_HACK
+    {
+	int r;
+
+	if (! ap_exists_config_define("NO_DETACH")) {
+	    if ((r = fork()) > 0)
+		return 0;
+	    if (r == -1) {
+		perror("fork");
+		return 0;
+	    }
+	    setsid();
+	}
+    }
+#endif
     ap_process_config_tree(server_conf, ap_conftree, process->pconf, ptemp);
     ap_fixup_virtual_hosts(pconf, server_conf);
     ap_fini_vhost_config(pconf, server_conf);
