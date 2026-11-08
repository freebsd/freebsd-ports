--- src/ucs/vfs/sock/vfs_sock.c.orig	2026-08-04 01:14:50 UTC
+++ src/ucs/vfs/sock/vfs_sock.c
@@ -19,11 +19,15 @@
 #include <sys/stat.h>
 #include <string.h>
 #include <assert.h>
+#include <stdlib.h>
 #include <unistd.h>
 #include <stdio.h>
 #include <errno.h>
 #include <pwd.h>
 #include <libgen.h>
+#if defined(__FreeBSD__)
+#include <sys/ucred.h>
+#endif
 
 
 typedef struct {
@@ -33,8 +37,29 @@ void ucs_vfs_sock_get_address(struct sockaddr_un *un_a
 
 void ucs_vfs_sock_get_address(struct sockaddr_un *un_addr)
 {
+#ifdef __FreeBSD__
+    const char *xdg_runtime_dir;
+    int ret;
+#endif
     memset(un_addr, 0, sizeof(*un_addr));
     un_addr->sun_family = AF_UNIX;
+#ifdef __FreeBSD__
+    /*
+     * Preserve an explicit UCX_VFS_SOCK_PATH override. When the default
+     * remains selected, prefer the runtime directory provided by the
+     * user's login session.
+     */
+    xdg_runtime_dir = getenv("XDG_RUNTIME_DIR");
+    if ((xdg_runtime_dir != NULL) && (xdg_runtime_dir[0] != '\0') &&
+        !strcmp(ucs_global_opts.vfs_sock_path,
+                UCX_VFS_SOCK_DEFAULT_PATH)) {
+        ret = snprintf(un_addr->sun_path, sizeof(un_addr->sun_path),
+                       "%s/ucx/vfs.sock", xdg_runtime_dir);
+        if ((ret >= 0) && ((size_t)ret < sizeof(un_addr->sun_path))) {
+            return;
+        }
+    }
+#endif
     ucs_fill_filename_template(ucs_global_opts.vfs_sock_path, un_addr->sun_path,
                                sizeof(un_addr->sun_path));
 }
@@ -43,6 +68,7 @@ int ucs_vfs_sock_mkdir(const char *sock_path, ucs_log_
 {
     const char *dirname;
     char *sock_path_dir;
+    struct stat st;
     int ret;
     ucs_status_t status;
 
@@ -57,8 +83,22 @@ int ucs_vfs_sock_mkdir(const char *sock_path, ucs_log_
     ret = mkdir(dirname, S_IRWXU);
     if (ret < 0) {
         if (errno == EEXIST) {
-            /* Directory already exists */
-            ret = 0;
+            if (lstat(dirname, &st) < 0) {
+                ret = -errno;
+                ucs_log(log_level, "failed to stat directory '%s': %m",
+                        dirname);
+            } else if (!S_ISDIR(st.st_mode) ||
+                       (st.st_uid != geteuid()) ||
+                       ((st.st_mode & (S_IWGRP | S_IWOTH)) != 0)) {
+                ret = -EPERM;
+                ucs_log(log_level,
+                        "unsafe VFS socket directory '%s': "
+                        "expected a directory owned by uid %u without "
+                        "group or world write permissions",
+                        dirname, (unsigned)geteuid());
+            } else {
+                ret = 0;
+            }
         } else {
             ucs_log(log_level, "failed to create directory '%s': %m",
                     sock_path_dir);
@@ -73,6 +113,7 @@ int ucs_vfs_sock_setopt_passcred(int sockfd)
 
 int ucs_vfs_sock_setopt_passcred(int sockfd)
 {
+#if defined(__linux__)
     int optval, ret;
 
     optval = 1;
@@ -80,6 +121,11 @@ int ucs_vfs_sock_setopt_passcred(int sockfd)
     if (ret < 0) {
         return -errno;
     }
+#else
+    /* FreeBSD retrieves credentials from connected local sockets using
+     * LOCAL_PEERCRED. Other platforms are currently a no-op. */
+    (void)sockfd;
+#endif
 
     return 0;
 }
@@ -97,7 +143,7 @@ int ucs_vfs_sock_send(int sockfd, const ucs_vfs_sock_m
 
 int ucs_vfs_sock_send(int sockfd, const ucs_vfs_sock_message_t *vfs_msg)
 {
-    char cbuf[CMSG_SPACE(sizeof(*vfs_msg))] UCS_V_ALIGNED(sizeof(size_t));
+    char cbuf[CMSG_SPACE(sizeof(vfs_msg->fd))] UCS_V_ALIGNED(sizeof(size_t));
     struct cmsghdr *cmsgp;
     struct msghdr msgh;
     ucs_vfs_msg_t msg;
@@ -132,7 +178,12 @@ int ucs_vfs_sock_recv(int sockfd, ucs_vfs_sock_message
 int ucs_vfs_sock_recv(int sockfd, ucs_vfs_sock_message_t *vfs_msg)
 {
     char cbuf[CMSG_SPACE(sizeof(*vfs_msg))] UCS_V_ALIGNED(sizeof(size_t));
+#if defined(__linux__)
     const struct ucred *cred;
+#elif defined(__FreeBSD__)
+    struct xucred cred;
+    socklen_t cred_len;
+#endif
     struct cmsghdr *cmsgp;
     struct msghdr msgh;
     ucs_vfs_msg_t msg;
@@ -163,27 +214,54 @@ int ucs_vfs_sock_recv(int sockfd, ucs_vfs_sock_message
 
     vfs_msg->action = msg.action;
 
-    cmsgp = CMSG_FIRSTHDR(&msgh);
-    if ((cmsgp == NULL) || (cmsgp->cmsg_level != SOL_SOCKET)) {
-        return -EINVAL;
-    }
-
     if (msg.action == UCS_VFS_SOCK_ACTION_MOUNT_REPLY) {
         /* expect file descriptor */
-        if ((cmsgp->cmsg_type != SCM_RIGHTS) ||
+        cmsgp = CMSG_FIRSTHDR(&msgh);
+        if ((cmsgp == NULL) ||
+            (cmsgp->cmsg_level != SOL_SOCKET) ||
+            (cmsgp->cmsg_type != SCM_RIGHTS) ||
             (cmsgp->cmsg_len != CMSG_LEN(sizeof(vfs_msg->fd)))) {
             return -EINVAL;
         }
 
         memcpy(&vfs_msg->fd, CMSG_DATA(cmsgp), sizeof(vfs_msg->fd));
     } else {
-        /* expect credentials */
+        /* expect peer credentials */
+#if defined(__FreeBSD__)
+        cred_len = sizeof(cred);
+        if (getsockopt(sockfd, SOL_LOCAL, LOCAL_PEERCRED, &cred,
+                       &cred_len) < 0) {
+            return -errno;
+        }
+
+        if ((cred_len != sizeof(cred)) ||
+            (cred.cr_version != XUCRED_VERSION)) {
+            return -EINVAL;
+        }
+
+        if ((cred.cr_uid != geteuid()) ||
+            (cred.cr_ngroups < 1) ||
+            (cred.cr_groups[0] != getegid())) {
+            return -EPERM;
+        }
+
+        if (msg.action == UCS_VFS_SOCK_ACTION_MOUNT) {
+            vfs_msg->pid = cred.cr_pid;
+        }
+#else
+        cmsgp = CMSG_FIRSTHDR(&msgh);
+        if ((cmsgp == NULL) ||
+            (cmsgp->cmsg_level != SOL_SOCKET)) {
+            return -EINVAL;
+        }
+
         if ((cmsgp->cmsg_type != SCM_CREDENTIALS) ||
-            (cmsgp->cmsg_len != CMSG_LEN(sizeof(*cred)))) {
+            (cmsgp->cmsg_len  != CMSG_LEN(sizeof(*cred)))) {
             return -EINVAL;
         }
 
         cred = (const struct ucred*)CMSG_DATA(cmsgp);
+
         if ((cred->uid != getuid()) || (cred->gid != getgid())) {
             return -EPERM;
         }
@@ -191,6 +269,7 @@ int ucs_vfs_sock_recv(int sockfd, ucs_vfs_sock_message
         if (msg.action == UCS_VFS_SOCK_ACTION_MOUNT) {
             vfs_msg->pid = cred->pid;
         }
+#endif
     }
 
     return 0;
