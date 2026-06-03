--- src/ucs/vfs/sock/vfs_sock.c.orig	2026-02-04 09:52:46 UTC
+++ src/ucs/vfs/sock/vfs_sock.c
@@ -24,6 +24,9 @@
 #include <errno.h>
 #include <pwd.h>
 #include <libgen.h>
+#if defined(__FreeBSD__)
+#include <sys/ucred.h>
+#endif
 
 
 typedef struct {
@@ -76,7 +79,13 @@ int ucs_vfs_sock_setopt_passcred(int sockfd)
     int optval, ret;
 
     optval = 1;
+#if defined(__linux__)
     ret = setsockopt(sockfd, SOL_SOCKET, SO_PASSCRED, &optval, sizeof(optval));
+#elif defined(__FreeBSD__)
+    ret = setsockopt(sockfd, SOL_LOCAL, LOCAL_CREDS, &optval, sizeof(optval));
+#else
+    ret = 0; /* no-op on other platforms for now */
+#endif
     if (ret < 0) {
         return -errno;
     }
@@ -132,7 +141,11 @@ int ucs_vfs_sock_recv(int sockfd, ucs_vfs_sock_message
 int ucs_vfs_sock_recv(int sockfd, ucs_vfs_sock_message_t *vfs_msg)
 {
     char cbuf[CMSG_SPACE(sizeof(*vfs_msg))] UCS_V_ALIGNED(sizeof(size_t));
+#if defined(__FreeBSD__)
+    const struct cmsgcred *cred;
+#else
     const struct ucred *cred;
+#endif
     struct cmsghdr *cmsgp;
     struct msghdr msgh;
     ucs_vfs_msg_t msg;
@@ -178,12 +191,30 @@ int ucs_vfs_sock_recv(int sockfd, ucs_vfs_sock_message
         memcpy(&vfs_msg->fd, CMSG_DATA(cmsgp), sizeof(vfs_msg->fd));
     } else {
         /* expect credentials */
+#if defined(__FreeBSD__)
+        if ((cmsgp->cmsg_level != SOL_SOCKET) ||
+            (cmsgp->cmsg_type  != SCM_CREDS) ||
+            (cmsgp->cmsg_len   != CMSG_LEN(sizeof(*cred)))) {
+            return -EINVAL;
+        }
+
+        cred = (const struct cmsgcred*)CMSG_DATA(cmsgp);
+
+        if ((cred->cmcred_euid != geteuid()) || (cred->cmcred_gid != getegid())) {
+            return -EPERM;
+        }
+
+        if (msg.action == UCS_VFS_SOCK_ACTION_MOUNT) {
+            vfs_msg->pid = cred->cmcred_pid;
+        }
+#else
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
@@ -191,6 +222,7 @@ int ucs_vfs_sock_recv(int sockfd, ucs_vfs_sock_message
         if (msg.action == UCS_VFS_SOCK_ACTION_MOUNT) {
             vfs_msg->pid = cred->pid;
         }
+#endif
     }
 
     return 0;
