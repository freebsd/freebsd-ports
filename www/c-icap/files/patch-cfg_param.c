--- cfg_param.c.orig	2014-11-21 23:05:59.123552647 +0100
+++ cfg_param.c	2014-11-21 23:08:29.362542582 +0100
@@ -40,7 +40,7 @@
 int ARGC;
 char **ARGV;
 
-struct ci_server_conf CONF = {
+struct ci_server_conf CI_CONF = {
      NULL, /* LISTEN ADDRESS */ 1344, /*PORT*/ AF_INET,    /*SOCK_FAMILY */
 #ifdef _WIN32
      "c:\\TEMP", /*TMPDIR*/ "c:\\TEMP\\c-icap.pid", /*PIDFILE*/ "\\\\.\\pipe\\c-icap",  /*COMMANDS_SOCKET; */
@@ -134,34 +134,34 @@
 };
 
 static struct ci_conf_entry conf_variables[] = {
-     {"ListenAddress", &CONF.ADDRESS, intl_cfg_set_str, NULL},
-     {"PidFile", &CONF.PIDFILE, intl_cfg_set_str, NULL},
-     {"CommandsSocket", &CONF.COMMANDS_SOCKET, intl_cfg_set_str, NULL},
+     {"ListenAddress", &CI_CONF.ADDRESS, intl_cfg_set_str, NULL},
+     {"PidFile", &CI_CONF.PIDFILE, intl_cfg_set_str, NULL},
+     {"CommandsSocket", &CI_CONF.COMMANDS_SOCKET, intl_cfg_set_str, NULL},
      {"Timeout", (void *) (&TIMEOUT), intl_cfg_set_int, NULL},
      {"KeepAlive", NULL, NULL, NULL},
      {"MaxKeepAliveRequests", &MAX_KEEPALIVE_REQUESTS, intl_cfg_set_int, NULL},
      {"KeepAliveTimeout", &KEEPALIVE_TIMEOUT, intl_cfg_set_int, NULL},
-     {"StartServers", &CONF.START_SERVERS, intl_cfg_set_int, NULL},
-     {"MaxServers", &CONF.MAX_SERVERS, intl_cfg_set_int, NULL},
-     {"MinSpareThreads", &CONF.MIN_SPARE_THREADS, intl_cfg_set_int, NULL},
-     {"MaxSpareThreads", &CONF.MAX_SPARE_THREADS, intl_cfg_set_int, NULL},
-     {"ThreadsPerChild", &CONF.THREADS_PER_CHILD, intl_cfg_set_int, NULL},
+     {"StartServers", &CI_CONF.START_SERVERS, intl_cfg_set_int, NULL},
+     {"MaxServers", &CI_CONF.MAX_SERVERS, intl_cfg_set_int, NULL},
+     {"MinSpareThreads", &CI_CONF.MIN_SPARE_THREADS, intl_cfg_set_int, NULL},
+     {"MaxSpareThreads", &CI_CONF.MAX_SPARE_THREADS, intl_cfg_set_int, NULL},
+     {"ThreadsPerChild", &CI_CONF.THREADS_PER_CHILD, intl_cfg_set_int, NULL},
      {"MaxRequestsPerChild", &MAX_REQUESTS_PER_CHILD, intl_cfg_set_int, NULL},
      {"MaxRequestsReallocateMem", &MAX_REQUESTS_BEFORE_REALLOCATE_MEM,
       intl_cfg_set_int, NULL},
-     {"Port", &CONF.PORT, intl_cfg_set_int, NULL},
-     {"User", &CONF.RUN_USER, intl_cfg_set_str, NULL},
-     {"Group", &CONF.RUN_GROUP, intl_cfg_set_str, NULL},
-     {"ServerAdmin", &CONF.SERVER_ADMIN, intl_cfg_set_str, NULL},
-     {"ServerName", &CONF.SERVER_NAME, intl_cfg_set_str, NULL},
+     {"Port", &CI_CONF.PORT, intl_cfg_set_int, NULL},
+     {"User", &CI_CONF.RUN_USER, intl_cfg_set_str, NULL},
+     {"Group", &CI_CONF.RUN_GROUP, intl_cfg_set_str, NULL},
+     {"ServerAdmin", &CI_CONF.SERVER_ADMIN, intl_cfg_set_str, NULL},
+     {"ServerName", &CI_CONF.SERVER_NAME, intl_cfg_set_str, NULL},
      {"LoadMagicFile", NULL, cfg_load_magicfile, NULL},
      {"Logger", &default_logger, cfg_set_logger, NULL},
      {"ServerLog", &SERVER_LOG_FILE, intl_cfg_set_str, NULL},
      {"AccessLog", NULL, cfg_set_accesslog, NULL},
      {"LogFormat", NULL, cfg_set_logformat, NULL},
      {"DebugLevel", NULL, cfg_set_debug_level, NULL},   /*Set library's debug level */
-     {"ServicesDir", &CONF.SERVICES_DIR, intl_cfg_set_str, NULL},
-     {"ModulesDir", &CONF.MODULES_DIR, intl_cfg_set_str, NULL},
+     {"ServicesDir", &CI_CONF.SERVICES_DIR, intl_cfg_set_str, NULL},
+     {"ModulesDir", &CI_CONF.MODULES_DIR, intl_cfg_set_str, NULL},
      {"Service", NULL, cfg_load_service, NULL},
      {"ServiceAlias", NULL, cfg_service_alias, NULL},
      {"Module", NULL, cfg_load_module, NULL},
@@ -451,7 +451,7 @@
      }
 
      db_file = argv[0];
-     if (strcmp(CONF.magics_file, db_file) == 0) {
+     if (strcmp(CI_CONF.magics_file, db_file) == 0) {
          ci_debug_printf(2, "The db file %s is the same as default. Ignoring...\n", db_file); 
          return 1;
      }
@@ -461,8 +461,8 @@
           ci_debug_printf(1, "Can not load magic file %s!!!\n", db_file);
           return 0;
      }
-     if (!CONF.MAGIC_DB)
-	 CONF.MAGIC_DB = ndb;
+     if (!CI_CONF.MAGIC_DB)
+	 CI_CONF.MAGIC_DB = ndb;
 
      return 1;
 }
@@ -517,24 +517,24 @@
           return 0;
      }
 
-     cfg_default_value_store(&CONF.TMPDIR, &CONF.TMPDIR, sizeof(char *));
+     cfg_default_value_store(&CI_CONF.TMPDIR, &CI_CONF.TMPDIR, sizeof(char *));
      len = strlen(argv[0]);
 
-     CONF.TMPDIR = ci_cfg_alloc_mem((len + 2) * sizeof(char));
-     strcpy(CONF.TMPDIR, argv[0]);
+     CI_CONF.TMPDIR = ci_cfg_alloc_mem((len + 2) * sizeof(char));
+     strcpy(CI_CONF.TMPDIR, argv[0]);
 #ifdef _WIN32
-     if (CONF.TMPDIR[len] != '\\') {
-          CONF.TMPDIR[len] = '\\';
-          CONF.TMPDIR[len + 1] = '\0';
+     if (CI_CONF.TMPDIR[len] != '\\') {
+          CI_CONF.TMPDIR[len] = '\\';
+          CI_CONF.TMPDIR[len + 1] = '\0';
      }
 #else
-     if (CONF.TMPDIR[len] != '/') {
-          CONF.TMPDIR[len] = '/';
-          CONF.TMPDIR[len + 1] = '\0';
+     if (CI_CONF.TMPDIR[len] != '/') {
+          CI_CONF.TMPDIR[len] = '/';
+          CI_CONF.TMPDIR[len + 1] = '\0';
      }
 #endif
      /*Check if tmpdir exists. If no try to build it , report an error and uses the default... */
-     CI_TMPDIR = CONF.TMPDIR;   /*Sets the library's temporary dir to .... */
+     CI_TMPDIR = CI_CONF.TMPDIR;   /*Sets the library's temporary dir to .... */
      ci_debug_printf(2, "Setting parameter :%s=%s\n", directive, argv[0]);
      return 1;
 }
@@ -842,7 +842,7 @@
 /* #endif */
 
 static struct ci_options_entry options[] = {
-     {opt_pre "f", "filename", &CONF.cfg_file, ci_cfg_set_str,
+     {opt_pre "f", "filename", &CI_CONF.cfg_file, ci_cfg_set_str,
       "Specify the configuration file"},
      {opt_pre "N", NULL, &DAEMON_MODE, ci_cfg_disable, "Do not run as daemon"},
      {opt_pre "d", "level", NULL, cfg_set_debug_level_cmd,
@@ -864,7 +864,7 @@
           ci_args_usage(argv[0], options);
           exit(-1);
      }
-     if (!parse_file(CONF.cfg_file)) {
+     if (!parse_file(CI_CONF.cfg_file)) {
           ci_debug_printf(1, "Error opening/parsing config file\n");
           exit(0);
      }
@@ -883,7 +883,7 @@
                           "Error in command line options, while reconfiguring!\n");
           return 0;
      }
-     if (!parse_file(CONF.cfg_file)) {
+     if (!parse_file(CI_CONF.cfg_file)) {
           ci_debug_printf(1,
                           "Error opening/parsing config file, while reconfiguring!\n");
           return 0;
@@ -923,7 +923,7 @@
         Release other subsystems
      */
     ci_magic_db_free();
-    CONF.MAGIC_DB = NULL;
+    CI_CONF.MAGIC_DB = NULL;
     ci_txt_template_close();
 }
 
@@ -939,9 +939,9 @@
 
      ci_debug_printf(1, "All resources released. Going to reload!\n");
      ci_txt_template_init();
-     if (!(CONF.MAGIC_DB = ci_magic_db_load(CONF.magics_file))) {
+     if (!(CI_CONF.MAGIC_DB = ci_magic_db_load(CI_CONF.magics_file))) {
           ci_debug_printf(1, "Can not load magic file %s!!!\n",
-                          CONF.magics_file);
+                          CI_CONF.magics_file);
      }
      init_modules();
      init_services();
@@ -950,15 +950,15 @@
         - Freeing all memory and resources used by configuration parameters (is it possible???)
         - reopen and read config file. Now the monitor process has now the new config parameters.
       */
-     old_port = CONF.PORT;
+     old_port = CI_CONF.PORT;
      if (!reconfig())
 	 return 0;
 
      /*
         - reinit listen socket if needed
       */
-     if (old_port != CONF.PORT) {
-          init_server(CONF.ADDRESS, CONF.PORT, &(CONF.PROTOCOL_FAMILY));
+     if (old_port != CI_CONF.PORT) {
+          init_server(CI_CONF.ADDRESS, CI_CONF.PORT, &(CI_CONF.PROTOCOL_FAMILY));
      }
 
      log_open();
