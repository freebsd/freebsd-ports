--- silcd/server.c.orig	Wed Nov  7 20:15:20 2001
+++ silcd/server.c	Sat Nov 10 12:50:39 2001
@@ -356,19 +356,42 @@ int silc_server_init(SilcServer server)
   return FALSE;
 }
 
-/* Fork server to background and set gid+uid to non-root.
-   Silcd will not run as root, so trying to set either user or group to
-   root will cause silcd to exit. */
+/* Fork server to background and set gid+uid to non-root */
 
 void silc_server_daemonise(SilcServer server)
 {
+  int i;
+
+  i = fork ();
+
+  if (i) {
+    if (i > 0) {
+      if (geteuid())
+        SILC_LOG_DEBUG(("Server started as user"));
+      else
+        SILC_LOG_DEBUG(("Server started as root. Dropping privileges."));
+
+      SILC_LOG_DEBUG(("Forking SILC server to background"));
+      exit(0);
+    } else {
+      SILC_LOG_DEBUG(("fork() failed, cannot proceed"));
+      exit(1);
+    }
+  }
+  setsid();
+}
+
+/* Drop root privligies. If this cannot be done, die. */
+
+void silc_server_drop(SilcServer server)
+{
   /* Are we executing silcd as root or a regular user? */
-  if (geteuid()==0) {
-    
+  if (!geteuid()) {
+
     struct passwd *pw;
     struct group *gr;
     char *user, *group;
-    
+
     if (!server->config->identity || !server->config->identity->user || 
 	!server->config->identity->group) {
       fprintf(stderr, "Error:"
@@ -378,11 +401,11 @@ void silc_server_daemonise(SilcServer se
        "\tthe server as non-root user.\n");
       exit(1);
     }
-    
+
     /* Get the values given for user and group in configuration file */
     user=server->config->identity->user;
     group=server->config->identity->group;
-    
+
     /* Check whether the user/group information is text */ 
     if (atoi(user)!=0 || atoi(group)!=0) {
       SILC_LOG_DEBUG(("Invalid user and/or group information"));
@@ -391,14 +414,14 @@ void silc_server_daemonise(SilcServer se
       fprintf(stderr, "Please assign them as names, not numbers\n");
       exit(1);
     }
-    
+
     /* Catch the nasty incident of string "0" returning 0 from atoi */
     if (strcmp("0", user)==0 || strcmp("0", group)==0) {
       SILC_LOG_DEBUG(("User and/or group configured to 0. Unacceptable"));
       fprintf(stderr, "User and/or group configured to 0. Exiting\n");
       exit(1);
     }
-    
+
     pw=getpwnam(user);
     gr=getgrnam(group);
 
@@ -411,7 +434,7 @@ void silc_server_daemonise(SilcServer se
       fprintf(stderr, "No such group %s found\n", group);
       exit(1);
     }
-    
+
     /* Check whether user and/or group is set to root. If yes, exit
        immediately. Otherwise, setgid and setuid server to user.group */
     if (gr->gr_gid==0 || pw->pw_uid==0) {
@@ -422,14 +445,6 @@ void silc_server_daemonise(SilcServer se
        "\tthe server as non-root user.\n");
       exit(1);
     } else {
-      /* Fork server to background, making it a daemon */
-      if (fork()) {
-        SILC_LOG_DEBUG(("Server started as root. Dropping privileges."));
-        SILC_LOG_DEBUG(("Forking SILC server to background"));
-        exit(0);
-      } 
-      setsid();
-      
       SILC_LOG_DEBUG(("Changing to group %s", group));
       if(setgid(gr->gr_gid)==0) {
         SILC_LOG_DEBUG(("Setgid to %s", group));
@@ -449,14 +464,6 @@ void silc_server_daemonise(SilcServer se
         exit(1);
       }
     }
-  } else {
-    /* Fork server to background, making it a daemon */
-    if (fork()) {
-      SILC_LOG_DEBUG(("Server started as user")); 
-      SILC_LOG_DEBUG(("Forking SILC server to background"));
-      exit(0);
-    }
-    setsid();
   }
 }
 
