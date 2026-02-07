--- scheduler/client.c.orig	2022-01-27 11:11:42 UTC
+++ scheduler/client.c
@@ -3514,8 +3514,8 @@ pipe_command(cupsd_client_t *con,	/* I - Client connec
   * Then execute the command...
   */
 
-  if (cupsdStartProcess(command, argv, envp, infile, fds[1], CGIPipes[1],
-			-1, -1, root, DefaultProfile, NULL, &pid) < 0)
+  if (!cupsdStartProcess(command, argv, envp, infile, fds[1], CGIPipes[1],
+			-1, -1, root, DefaultProfile, NULL, &pid))
   {
    /*
     * Error - can't fork!
