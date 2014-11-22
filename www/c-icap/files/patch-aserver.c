--- aserver.c.orig	2014-11-21 23:14:37.959523762 +0100
+++ aserver.c	2014-11-21 23:15:01.595515118 +0100
@@ -125,9 +125,9 @@
      ci_txt_template_set_dir(DATADIR"templates");
      commands_init();
 
-     if (!(CONF.MAGIC_DB = ci_magic_db_load(CONF.magics_file))) {
+     if (!(CI_CONF.MAGIC_DB = ci_magic_db_load(CI_CONF.magics_file))) {
           ci_debug_printf(1, "Can not load magic file %s!!!\n",
-                          CONF.magics_file);
+                          CI_CONF.magics_file);
      }
      init_conf_tables();
      request_stats_init();
@@ -143,22 +143,22 @@
      }
 
 #if ! defined(_WIN32)
-     if (is_icap_running(CONF.PIDFILE)) {
+     if (is_icap_running(CI_CONF.PIDFILE)) {
           ci_debug_printf(1, "c-icap server already running!\n");
           exit(-1);
      }
      if (DAEMON_MODE)
           run_as_daemon();
-     if (!set_running_permissions(CONF.RUN_USER, CONF.RUN_GROUP))
+     if (!set_running_permissions(CI_CONF.RUN_USER, CI_CONF.RUN_GROUP))
           exit(-1);
-     store_pid(CONF.PIDFILE);
+     store_pid(CI_CONF.PIDFILE);
 #endif
 
-     if (!init_server(CONF.ADDRESS, CONF.PORT, &(CONF.PROTOCOL_FAMILY)))
+     if (!init_server(CI_CONF.ADDRESS, CI_CONF.PORT, &(CI_CONF.PROTOCOL_FAMILY)))
           return -1;
      post_init_modules();
      post_init_services();
      start_server();
-     clear_pid(CONF.PIDFILE);
+     clear_pid(CI_CONF.PIDFILE);
      return 0;
 }
