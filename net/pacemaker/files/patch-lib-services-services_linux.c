--- lib/services/services_linux.c.orig	2016-01-14 21:43:08 UTC
+++ lib/services/services_linux.c
@@ -457,13 +457,19 @@ action_launch_child(svc_action_t *op)
     _exit(op->rc);
 }
 
+#ifndef HAVE_SYS_SIGNALFD_H
+static int sigchld_pipe[2];
+
 static void
-action_synced_wait(svc_action_t * op, sigset_t mask)
+sigchld_handler()
 {
+    write(sigchld_pipe[1], "", 1);
+}
+#endif
 
-#ifndef HAVE_SYS_SIGNALFD_H
-    CRM_ASSERT(FALSE);
-#else
+static void
+action_synced_wait(svc_action_t * op, sigset_t *mask)
+{
     int status = 0;
     int timeout = op->timeout;
     int sfd = -1;
@@ -471,10 +477,14 @@ action_synced_wait(svc_action_t * op, si
     struct pollfd fds[3];
     int wait_rc = 0;
 
-    sfd = signalfd(-1, &mask, SFD_NONBLOCK);
+#ifdef HAVE_SYS_SIGNALFD_H
+    sfd = signalfd(-1, mask, SFD_NONBLOCK);
     if (sfd < 0) {
         crm_perror(LOG_ERR, "signalfd() failed");
     }
+#else
+    sfd = sigchld_pipe[0];
+#endif
 
     fds[0].fd = op->opaque->stdout_fd;
     fds[0].events = POLLIN;
@@ -503,6 +513,7 @@ action_synced_wait(svc_action_t * op, si
             }
 
             if (fds[2].revents & POLLIN) {
+#ifdef HAVE_SYS_SIGNALFD_H
                 struct signalfd_siginfo fdsi;
                 ssize_t s;
 
@@ -511,6 +522,12 @@ action_synced_wait(svc_action_t * op, si
                     crm_perror(LOG_ERR, "Read from signal fd %d failed", sfd);
 
                 } else if (fdsi.ssi_signo == SIGCHLD) {
+#else
+                if (1) {
+                    /* Clear out the sigchld pipe. */
+                    char ch;
+                    while (read(sfd, &ch, 1) == 1);
+#endif
                     wait_rc = waitpid(op->pid, &status, WNOHANG);
 
                     if (wait_rc < 0){
@@ -583,10 +600,10 @@ action_synced_wait(svc_action_t * op, si
 
     close(op->opaque->stdout_fd);
     close(op->opaque->stderr_fd);
-    close(sfd);
 
+#ifdef HAVE_SYS_SIGNALFD_H
+    close(sfd);
 #endif
-
 }
 
 /* For an asynchronous 'op', returns FALSE if 'op' should be free'd by the caller */
@@ -596,9 +613,30 @@ services_os_action_execute(svc_action_t 
 {
     int stdout_fd[2];
     int stderr_fd[2];
+    struct stat st;
+    sigset_t *pmask;
+
+#ifdef HAVE_SYS_SIGNALFD_H
     sigset_t mask;
     sigset_t old_mask;
-    struct stat st;
+#define sigchld_cleanup() {                                                   \
+    if (sigismember(&old_mask, SIGCHLD) == 0) {                               \
+        if (sigprocmask(SIG_UNBLOCK, &mask, NULL) < 0) {                      \
+            crm_perror(LOG_ERR, "sigprocmask() failed to unblock sigchld");   \
+        }                                                                     \
+    }                                                                         \
+}
+#else
+    struct sigaction sa;
+    struct sigaction old_sa;
+#define sigchld_cleanup() {                                                   \
+    if (sigaction(SIGCHLD, &old_sa, NULL) < 0) {                              \
+        crm_perror(LOG_ERR, "sigaction() failed to remove sigchld handler");  \
+    }                                                                         \
+    close(sigchld_pipe[0]);                                                   \
+    close(sigchld_pipe[1]);                                                   \
+}
+#endif
 
     if (pipe(stdout_fd) < 0) {
         crm_err("pipe() failed");
@@ -620,13 +658,33 @@ services_os_action_execute(svc_action_t 
     }
 
     if (synchronous) {
+#ifdef HAVE_SYS_SIGNALFD_H
         sigemptyset(&mask);
         sigaddset(&mask, SIGCHLD);
         sigemptyset(&old_mask);
 
         if (sigprocmask(SIG_BLOCK, &mask, &old_mask) < 0) {
-            crm_perror(LOG_ERR, "sigprocmask() failed");
+            crm_perror(LOG_ERR, "sigprocmask() failed to block sigchld");
+        }
+
+        pmask = &mask;
+#else
+        if(pipe(sigchld_pipe) == -1) {
+            crm_perror(LOG_ERR, "pipe() failed");
+        }
+
+        set_fd_opts(sigchld_pipe[0], O_NONBLOCK);
+        set_fd_opts(sigchld_pipe[1], O_NONBLOCK);
+
+        sa.sa_handler = sigchld_handler;
+        sa.sa_flags = 0;
+        sigemptyset(&sa.sa_mask);
+        if (sigaction(SIGCHLD, &sa, &old_sa) < 0) {
+            crm_perror(LOG_ERR, "sigaction() failed to set sigchld handler");
         }
+
+        pmask = NULL;
+#endif
     }
 
     op->pid = fork();
@@ -645,6 +703,8 @@ services_os_action_execute(svc_action_t 
                 if (!synchronous) {
                     return operation_finalize(op);
                 }
+
+                sigchld_cleanup();
                 return FALSE;
             }
         case 0:                /* Child */
@@ -663,6 +723,10 @@ services_os_action_execute(svc_action_t 
                 close(stderr_fd[1]);
             }
 
+            if (synchronous) {
+                sigchld_cleanup();
+            }
+
             action_launch_child(op);
     }
 
@@ -677,14 +741,8 @@ services_os_action_execute(svc_action_t 
     set_fd_opts(op->opaque->stderr_fd, O_NONBLOCK);
 
     if (synchronous) {
-        action_synced_wait(op, mask);
-
-        if (sigismember(&old_mask, SIGCHLD) == 0) {
-            if (sigprocmask(SIG_UNBLOCK, &mask, NULL) < 0) {
-                crm_perror(LOG_ERR, "sigprocmask() to unblocked failed");
-            }
-        }
-
+        action_synced_wait(op, pmask);
+        sigchld_cleanup();
     } else {
 
         crm_trace("Async waiting for %d - %s", op->pid, op->opaque->exec);
