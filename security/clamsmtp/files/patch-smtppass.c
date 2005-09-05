diff -ur ../clamsmtp-1.5-orig/common/smtppass.c common/smtppass.c
--- common/smtppass.c	Tue Aug  2 01:23:05 2005
+++ common/smtppass.c	Sun Sep  4 11:52:13 2005
@@ -275,6 +275,26 @@
 
     sp_messagex(NULL, LOG_DEBUG, "starting up (%s)...", VERSION);
 
+    /* Drop privileges before daemonizing */
+    drop_privileges();
+    
+    /* When set to this we daemonize */
+    if(g_state.debug_level == -1)
+    {
+        /* Fork a daemon nicely here */
+        if(daemon(0, 0) == -1)
+        {
+            sp_message(NULL, LOG_ERR, "couldn't run as daemon");
+            exit(1);
+        }
+      
+        sp_messagex(NULL, LOG_DEBUG, "running as a daemon");
+        g_state.daemonized = 1;
+
+        /* Open the system log */
+        openlog(g_state.name, 0, LOG_MAIL);
+    }
+
     /* Create the socket */
     sock = socket(SANY_TYPE(g_state.listenaddr), SOCK_STREAM, 0);
     if(sock < 0)
@@ -297,26 +317,6 @@
         exit(1);
     }
       	
-    /* Drop privileges before daemonizing */
-    drop_privileges();
-    
-    /* When set to this we daemonize */
-    if(g_state.debug_level == -1)
-    {
-        /* Fork a daemon nicely here */
-        if(daemon(0, 0) == -1)
-        {
-            sp_message(NULL, LOG_ERR, "couldn't run as daemon");
-            exit(1);
-        }
-      
-        sp_messagex(NULL, LOG_DEBUG, "running as a daemon");
-        g_state.daemonized = 1;
-
-        /* Open the system log */
-        openlog(g_state.name, 0, LOG_MAIL);
-    }
-
     sp_messagex(NULL, LOG_DEBUG, "created socket: %s", g_state.listenname);
 
     /* Handle some signals */
