--- server.c.orig	Sun Mar 20 11:17:45 2005
+++ server.c	Sun Mar 20 10:09:04 2005
@@ -66,7 +66,7 @@
       dir = g_new (CrashDir, 1);
       dir->time = now;
       dir->path = g_strdup_printf ("%s/%d.%d.%d.%d-%s",
-				   NETDUMP_DIR_PREFIX,
+				   config.dumpdirprefix,
 				   (ip >> 24) & 0xff,
 				   (ip >> 16) & 0xff,
 				   (ip >> 8) & 0xff,
@@ -100,7 +100,7 @@
   char *cmdline;
   int res = -1;
 
-  filename = g_strconcat (NETDUMP_DIR_PREFIX "/scripts/",
+  filename = g_strconcat (config.dumpdirprefix, "/scripts/",
 			  script,
 			  NULL);
   
@@ -147,7 +147,7 @@
     }
 
   path = g_strdup_printf ("%s/magic/%d.%d.%d.%d",
-			 NETDUMP_DIR_PREFIX,
+			 config.dumpdirprefix,
 			 (ip >> 24) & 0xff,
 			 (ip >> 16) & 0xff,
 			 (ip >> 8) & 0xff,
@@ -373,10 +373,10 @@
 
   openlog("netdump", LOG_PID, LOG_DAEMON);
 
-  if (chdir (NETDUMP_DIR_PREFIX) == -1)
+  if (chdir (config.dumpdirprefix) == -1)
     {
-      syslog (LOG_ERR, "can't cd to %s", NETDUMP_DIR_PREFIX);
-      fprintf (stderr, "can't cd to %s", NETDUMP_DIR_PREFIX);
+      syslog (LOG_ERR, "can't cd to %s", config.dumpdirprefix);
+      fprintf (stderr, "can't cd to %s\n", config.dumpdirprefix);
       exit (1);
     }
   
@@ -429,6 +429,11 @@
 
   loop = g_main_new (TRUE);
   g_main_run (loop);
+
+  if (config.pidfile != NULL)
+    free(config.pidfile);
+  if (config.dumpdirprefix != NULL)
+    free(config.dumpdirprefix);
 
   return 0;
 }
