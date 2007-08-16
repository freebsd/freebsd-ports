--- src/dird/dird.c	2007-06-07 10:46:43.000000000 -0400
+++ src/dird/dird.c	2007-08-16 08:58:20.000000000 -0400
@@ -228,6 +228,15 @@
       Jmsg((JCR *)NULL, M_ERROR_TERM, 0, _("Please correct configuration file: %s\n"), configfile);
    }
 
+   if (background) {
+      daemon_start();
+      init_stack_dump();              /* grab new pid */
+   }
+
+   /* Create pid must come after we are a daemon -- so we have our final pid */
+   create_pid_file(director->pid_directory, "bacula-dir", get_first_port_host_order(director->DIRaddrs));
+   read_state_file(director->working_directory, "bacula-dir", get_first_port_host_order(director->DIRaddrs));
+
    drop(uid, gid);                    /* reduce privileges if requested */
 
    if (!check_catalog()) {
@@ -247,14 +256,6 @@
    FDConnectTimeout = (int)director->FDConnectTimeout;
    SDConnectTimeout = (int)director->SDConnectTimeout;
 
-   if (background) {
-      daemon_start();
-      init_stack_dump();              /* grab new pid */
-   }
-
-   /* Create pid must come after we are a daemon -- so we have our final pid */
-   create_pid_file(director->pid_directory, "bacula-dir", get_first_port_host_order(director->DIRaddrs));
-   read_state_file(director->working_directory, "bacula-dir", get_first_port_host_order(director->DIRaddrs));
 
 
 #if !defined(HAVE_WIN32)
