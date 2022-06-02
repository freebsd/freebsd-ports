Work around FD_ISSET() accessing an invalid address

and preventing modules such as caca.so to load sucessfully:

# gdb /usr/local/sbin/vlock-main
(gdb) set args caca
(gdb) set environment VLOCK_TIMEOUT=2
(gdb) set follow-fork-mode child
(gdb) run
Thread 2.1 received signal SIGBUS, Bus error.
Object-specific hardware error.
[Switching to LWP 100235 of process 83087]
0x00000000002075b0 in close_fds (except_fds=0x7fffffffe668) at src/process.c:125
125         if (!FD_ISSET(fd, except_fds))
(gdb) p fd
$1 = 52416

--- src/process.c.orig	2011-09-18 15:22:35 UTC
+++ src/process.c
@@ -105,27 +105,6 @@ void ensure_death(pid_t pid)
   (void) waitpid(pid, &status, 0);
 }
 
-/* Close all possibly open file descriptors except the ones specified in the
- * given set. */
-static void close_fds(fd_set *except_fds)
-{
-  struct rlimit r;
-  int maxfd;
-
-  /* Get the maximum number of file descriptors. */
-  if (getrlimit(RLIMIT_NOFILE, &r) == 0)
-    maxfd = r.rlim_cur;
-  else
-    /* Hopefully safe default. */
-    maxfd = 1024;
-
-  /* Close all possibly open file descriptors except STDIN_FILENO,
-   * STDOUT_FILENO and STDERR_FILENO. */
-  for (int fd = 0; fd < maxfd; fd++)
-    if (!FD_ISSET(fd, except_fds))
-      (void) close(fd);
-}
-
 static int open_devnull(void)
 {
   static int devnull_fd = -1;
@@ -175,8 +154,6 @@ bool create_child(struct child_process *child)
 
   if (child->pid == 0) {
     /* Child. */
-    fd_set except_fds;
-
     if (child->stdin_fd == REDIRECT_PIPE)
       (void) dup2(stdin_pipe[0], STDIN_FILENO);
     else if (child->stdin_fd == REDIRECT_DEV_NULL)
@@ -198,13 +175,7 @@ bool create_child(struct child_process *child)
     else if (child->stderr_fd != NO_REDIRECT)
       (void) dup2(child->stderr_fd, STDERR_FILENO);
 
-    FD_ZERO(&except_fds);
-    FD_SET(STDIN_FILENO, &except_fds);
-    FD_SET(STDOUT_FILENO, &except_fds);
-    FD_SET(STDERR_FILENO, &except_fds);
-    FD_SET(status_pipe[1], &except_fds);
-
-    (void) close_fds(&except_fds);
+    (void) closefrom(status_pipe[1] + 1);
 
     (void) setgid(getgid());
     (void) setuid(getuid());
