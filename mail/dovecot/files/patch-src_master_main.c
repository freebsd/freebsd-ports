--- src/master/main.c.orig	2018-03-20 03:15:40.000000000 -0700
+++ src/master/main.c	2018-05-05 18:57:32.485732000 -0700
@@ -861,6 +861,8 @@
 		i_fatal("dup2(dev_null_fd) failed: %m");
 	if (!foreground && dup2(dev_null_fd, STDOUT_FILENO) < 0)
 		i_fatal("dup2(dev_null_fd) failed: %m");
+	if (!foreground && dup2(dev_null_fd, STDERR_FILENO) < 0)
+		i_fatal("dup2(dev_null_fd) failed: %m");
 
 	pidfile_path =
 		i_strconcat(set->base_dir, "/"MASTER_PID_FILE_NAME, NULL);
