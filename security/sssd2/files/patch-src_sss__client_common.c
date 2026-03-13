--- src/sss_client/common.c.orig	2026-03-13 11:57:05 UTC
+++ src/sss_client/common.c
@@ -1034,7 +1034,7 @@ static errno_t check_server_cred(int sockfd)
         return EFAULT;
     }
 
-    ret = getsockopt(sockfd, SOL_SOCKET, SSS_PEERCRED_SOCKET_OPTION, &server_cred,
+    ret = getsockopt(sockfd, SSS_PEERCRED_OPTION_LEVEL, SSS_PEERCRED_SOCKET_OPTION, &server_cred,
                      &server_cred_len);
     if (ret != 0) {
         return errno;
