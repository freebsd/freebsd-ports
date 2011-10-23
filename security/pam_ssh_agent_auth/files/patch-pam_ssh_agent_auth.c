--- ./pam_ssh_agent_auth.c	2011-01-26 15:59:21.000000000 -0500
+++ ../../pam_ssh_agent_auth-0.9.3.fixed/pam_ssh_agent_auth.c	2011-10-10 13:10:35.866387792 -0400
@@ -124,7 +124,7 @@
     pam_get_item(pamh, PAM_USER, (void *) &user);
     pam_get_item(pamh, PAM_RUSER, (void *) &ruser_ptr);
 
-    verbose("Beginning pam_ssh_agent_auth for user %s", user);
+    pam_ssh_auth_verbose("Beginning pam_ssh_agent_auth for user %s", user);
 
     if(ruser_ptr) {
         strncpy(ruser, ruser_ptr, sizeof(ruser) - 1);
@@ -139,12 +139,12 @@
 #ifdef ENABLE_SUDO_HACK
         if( (strlen(sudo_service_name) > 0) && strncasecmp(servicename, sudo_service_name, sizeof(sudo_service_name) - 1) == 0 && getenv("SUDO_USER") ) {
             strncpy(ruser, getenv("SUDO_USER"), sizeof(ruser) - 1 );
-            verbose( "Using environment variable SUDO_USER (%s)", ruser );
+            pam_ssh_auth_verbose( "Using environment variable SUDO_USER (%s)", ruser );
         } else 
 #endif
         {
             if( ! getpwuid(getuid()) ) {
-                verbose("Unable to getpwuid(getuid())");
+                pam_ssh_auth_verbose("Unable to getpwuid(getuid())");
                 goto cleanexit;
             }
             strncpy(ruser, getpwuid(getuid())->pw_name, sizeof(ruser) - 1);
@@ -153,11 +153,11 @@
 
     /* Might as well explicitely confirm the user exists here */
     if(! getpwnam(ruser) ) {
-        verbose("getpwnam(%s) failed, bailing out", ruser);
+        pam_ssh_auth_verbose("getpwnam(%s) failed, bailing out", ruser);
         goto cleanexit;
     }
     if( ! getpwnam(user) ) {
-        verbose("getpwnam(%s) failed, bailing out", user);
+        pam_ssh_auth_verbose("getpwnam(%s) failed, bailing out", user);
         goto cleanexit;
     }
 
@@ -167,7 +167,7 @@
          */
         parse_authorized_key_file(user, authorized_keys_file_input);
     } else {
-        verbose("Using default file=/etc/security/authorized_keys");
+        pam_ssh_auth_verbose("Using default file=/etc/security/authorized_keys");
         authorized_keys_file = xstrdup("/etc/security/authorized_keys");
     }
 
@@ -177,7 +177,7 @@
      */
 
     if(user && strlen(ruser) > 0) {
-        verbose("Attempting authentication: `%s' as `%s' using %s", ruser, user, authorized_keys_file);
+        pam_ssh_auth_verbose("Attempting authentication: `%s' as `%s' using %s", ruser, user, authorized_keys_file);
 
         /* 
          * this pw_uid is used to validate the SSH_AUTH_SOCK, and so must be the uid of the ruser invoking the program, not the target-user
