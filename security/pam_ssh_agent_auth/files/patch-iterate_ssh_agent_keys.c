--- ./iterate_ssh_agent_keys.c	2010-01-12 21:17:01.000000000 -0500
+++ ../../pam_ssh_agent_auth-0.9.3.fixed/iterate_ssh_agent_keys.c	2011-10-10 13:10:35.864389493 -0400
@@ -82,7 +82,7 @@
     session_id2 = session_id2_gen();
 
     if ((ac = ssh_get_authentication_connection(uid))) {
-        verbose("Contacted ssh-agent of user %s (%u)", getpwuid(uid)->pw_name, uid);
+        pam_ssh_auth_verbose("Contacted ssh-agent of user %s (%u)", getpwuid(uid)->pw_name, uid);
         for (key = ssh_get_first_identity(ac, &comment, 2); key != NULL; key = ssh_get_next_identity(ac, &comment, 2)) 
         {
             if(key != NULL) {
@@ -103,7 +103,7 @@
         ssh_close_authentication_connection(ac);
     }
     else {
-        verbose("No ssh-agent could be contacted");
+        pam_ssh_auth_verbose("No ssh-agent could be contacted");
     }
     xfree(session_id2);
     EVP_cleanup();
