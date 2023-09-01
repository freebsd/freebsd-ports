--- process.c.orig	2023-09-01 07:49:12 UTC
+++ process.c
@@ -75,6 +75,8 @@ static void ptrace(__attribute__((unused)) int x,
 		   __attribute__((unused)) int w) {}
 #endif
 
+int ARGC;
+char **ARGV;
 
 #if defined(__linux__) || defined(__CYGWIN__) || (defined(__NetBSD__) && !defined(KERN_PROC_PATHNAME))
 static int pid_to_cmd(pid_t pid, char *cmd, size_t cmd_size)
