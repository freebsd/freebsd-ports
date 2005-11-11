--- configuration.c.orig	Sun Mar 20 11:17:08 2005
+++ configuration.c	Sun Mar 20 10:06:04 2005
@@ -2,6 +2,7 @@
 #include <string.h>
 #include <unistd.h>
 #include <stdio.h>
+#include <stdlib.h>
 #include <syslog.h>
 #include <sys/types.h>
 #include <sys/stat.h>
@@ -15,6 +16,8 @@
 
 NetdumpConfiguration config;
 
+char *netdump_dir_prefix = NETDUMP_DIR_PREFIX;
+
 enum ConfigType {
   CONFIG_NONE,
   CONFIG_BOOLEAN,
@@ -46,6 +49,7 @@
   { "max_concurrent_dumps", CONFIG_INT, CONFIG_OFFSET(max_concurrent_dumps), GINT_TO_POINTER (4) },
   { "daemon", CONFIG_BOOLEAN, CONFIG_OFFSET(daemon), GINT_TO_POINTER (0) },
   { "pidfile", CONFIG_STRING, CONFIG_OFFSET(pidfile), NULL },
+  { "dumpdirprefix", CONFIG_STRING, CONFIG_OFFSET(dumpdirprefix), NETDUMP_DIR_PREFIX },
   { "secure", CONFIG_INT, CONFIG_OFFSET(secure), GINT_TO_POINTER (1) },
   { "space_check", CONFIG_INT, CONFIG_OFFSET(space_check), GINT_TO_POINTER (1) },
 };
@@ -118,7 +122,20 @@
       *(guint16 *)ptr = GPOINTER_TO_INT (config_data[i].default_value);
       break;
     case CONFIG_STRING:
-      *(gchar **)ptr = (gchar *)config_data[i].default_value;
+      if (config_data[i].default_value != NULL) {
+        *(char **)ptr = (char *)malloc(strlen(config_data[i].default_value) + 1);
+	if (*(char **)ptr != NULL) {
+		strncpy(*(char **)ptr, config_data[i].default_value, strlen(config_data[i].default_value));
+		(*(char **)ptr)[strlen(config_data[i].default_value)] = '\0';
+	}
+	else {
+		syslog(LOG_ERR, "Cannot malloc\n");
+		exit(1);
+	}
+      }
+      else
+	ptr = (char *)NULL;
+
       break;
     case CONFIG_NONE:
       break;
@@ -181,7 +198,18 @@
     if (token != G_TOKEN_STRING)
       return G_TOKEN_STRING;
 
-    *(char **)ptr = scanner->value.v_string;
+    if (*(char **)ptr != NULL)
+	free(*(char **)ptr);
+    *(char **)ptr = (char *)malloc(strlen(scanner->value.v_string) + 1);
+	if (*(char **)ptr != NULL) {
+		strncpy(*(char **)ptr, scanner->value.v_string, strlen(scanner->value.v_string));
+		(*(char **)ptr)[strlen(scanner->value.v_string)] = '\0';
+	}
+	else {
+		syslog(LOG_ERR, "Cannot malloc\n");
+		exit(1);
+	}
+
     break;
   case CONFIG_NONE:
     break;
@@ -277,6 +305,8 @@
       "run in background as a daemon", NULL },
     { "pidfile",  'P', POPT_ARG_STRING, &config.pidfile, 0,
       "file in which to store the pid", "path" },
+    { "dumpdirprefix",  'D', POPT_ARG_STRING, &config.dumpdirprefix, 0,
+      "dir in which to store dumps", "/var/spool/netdump" },
     { "secure", 's', POPT_ARG_INT, &config.secure, 0,
       "use ssh to send client identification", "1" },
     { "space_check", 'S', POPT_ARG_INT, &config.space_check, 0,
@@ -305,7 +335,7 @@
   /* Set the default values */
   config_set_defaults();
 
-  config_load ("/etc/netdump.conf");
+  config_load ("/usr/local/etc/netdump.conf");
   
   optCon = poptGetContext("netdump-server", argc, (const char **)argv,
 			  optionsTable, 0);
