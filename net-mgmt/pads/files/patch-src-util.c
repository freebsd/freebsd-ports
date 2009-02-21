--- src/util.orig.c	2009-02-11 10:29:24.000000000 -0500
+++ src/util.c	2009-02-11 10:30:36.000000000 -0500
@@ -117,16 +117,18 @@
     struct passwd *this_user;
 
     /* Default PID File */
-    if (gc.pid_file->slen >= 0)
-        gc.pid_file = bfromcstr("/var/run/pads.pid");
+    if (pid_file == NULL) {
+        pid_file = bfromcstr("/var/run/pads.pid");
+        gc.pid_file = bfromcstr("/var/run/pads.pid"); // Needed to unlink
+    }
 
     /* Create PID File */
-    if ((fp = fopen(bdata(gc.pid_file), "w")) != NULL) {
+    if ((fp = fopen(bdata(pid_file), "w")) != NULL) {
         pid = (int) getpid();
         fprintf(fp, "%d\n", pid);
         fclose(fp);
     } else {
-        err_message("Unable to create PID file (%s).\n", bdata(gc.pid_file));
+        err_message("Unable to create PID file (%s).\n", bdata(pid_file));
     }
 
     /* Change PID File's Ownership */
@@ -137,7 +139,7 @@
         err_message("'%s' group does not appear to exist.", bdata(group));
     if ((this_user = getpwnam(bdata(user))) == NULL)
         err_message("'%s' user does not appear to exist.", bdata(user));
-    if ((chown(pid_file, this_user->pw_uid, this_group->gr_gid)) != 0)
+    if ((chown(bdata(pid_file), this_user->pw_uid, this_group->gr_gid)) != 0)
         err_message("Unable to change PID file's ownership.");
 
 }
