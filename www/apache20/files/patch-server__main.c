--- ./server/main.c.orig	2007-08-28 01:23:46.000000000 -0400
+++ ./server/main.c	2010-05-06 16:06:03.772831938 -0400
@@ -40,6 +40,11 @@
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
@@ -554,6 +559,21 @@
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
