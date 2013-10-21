diff --git a/sysdep/unix/main.c b/sysdep/unix/main.c
index bd80ba2..c7db7c8 100644
--- sysdep/unix/main.c
+++ sysdep/unix/main.c
@@ -473,6 +473,58 @@ cli_init_unix(uid_t use_uid, gid_t use_gid)
 }
 
 /*
+ *	PID file
+ */
+
+static char *pid_file;
+static int pid_fd;
+
+static inline void
+open_pid_file(void)
+{
+  if (!pid_file)
+    return;
+
+  pid_fd = open(pid_file, O_WRONLY|O_CREAT, 0664);
+  if (pid_fd < 0)
+    die("Cannot create PID file %s: %m", pid_file);
+}
+
+static inline void
+write_pid_file(void)
+{
+  int pl, rv;
+  char ps[24];
+
+  if (!pid_file)
+    return;
+
+  /* We don't use PID file for uniqueness, so no need for locking */
+
+  pl = bsnprintf(ps, sizeof(ps), "%ld\n", (long) getpid());
+  if (pl < 0)
+    bug("PID buffer too small");
+
+  rv = ftruncate(pid_fd, 0);
+  if (rv < 0)
+    die("fruncate: %m");
+    
+  rv = write(pid_fd, ps, pl);
+  if(rv < 0)
+    die("write: %m");
+
+  close(pid_fd);
+}
+
+static inline void
+unlink_pid_file(void)
+{
+  if (pid_file)
+    unlink(pid_file);
+}
+
+
+/*
  *	Shutdown
  */
 
@@ -496,6 +548,7 @@ async_shutdown(void)
 void
 sysdep_shutdown_done(void)
 {
+  unlink_pid_file();
   unlink(path_control_socket);
   log_msg(L_FATAL "Shutdown completed");
   exit(0);
@@ -548,7 +601,7 @@ signal_init(void)
  *	Parsing of command-line arguments
  */
 
-static char *opt_list = "c:dD:ps:u:g:";
+static char *opt_list = "c:dD:ps:P:u:g:";
 static int parse_and_exit;
 char *bird_name;
 static char *use_user;
@@ -557,7 +610,7 @@ static char *use_group;
 static void
 usage(void)
 {
-  fprintf(stderr, "Usage: %s [-c <config-file>] [-d] [-D <debug-file>] [-p] [-s <control-socket>] [-u <user>] [-g <group>]\n", bird_name);
+  fprintf(stderr, "Usage: %s [-c <config-file>] [-d] [-D <debug-file>] [-p] [-s <control-socket>] [-P <pid-file>] [-u <user>] [-g <group>]\n", bird_name);
   exit(1);
 }
 
@@ -656,6 +709,9 @@ parse_args(int argc, char **argv)
       case 's':
 	path_control_socket = optarg;
 	break;
+      case 'P':
+	pid_file = optarg;
+	break;
       case 'u':
 	use_user = optarg;
 	break;
@@ -709,6 +765,9 @@ main(int argc, char **argv)
   if (use_uid)
     drop_uid(use_uid);
 
+  if (!parse_and_exit)
+    open_pid_file();
+
   protos_build();
   proto_build(&proto_unix_kernel);
   proto_build(&proto_unix_iface);
@@ -733,6 +792,8 @@ main(int argc, char **argv)
       dup2(0, 2);
     }
 
+  write_pid_file();
+
   signal_init();
 
 #ifdef LOCAL_DEBUG
