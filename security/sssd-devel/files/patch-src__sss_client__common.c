--- src/sss_client/common.c.orig	2023-05-05 08:11:07 UTC
+++ src/sss_client/common.c
@@ -156,7 +156,7 @@ static enum sss_status sss_cli_send_req(enum sss_cli_c
             *errnop = error;
             break;
         case 0:
-            *errnop = ETIME;
+            *errnop = ETIMEDOUT;
             break;
         case 1:
             if (pfd.revents & (POLLERR | POLLHUP)) {
@@ -268,7 +268,7 @@ static enum sss_status sss_cli_recv_rep(enum sss_cli_c
             *errnop = error;
             break;
         case 0:
-            *errnop = ETIME;
+            *errnop = ETIMEDOUT;
             break;
         case 1:
             if (pfd.revents & (POLLHUP)) {
@@ -731,7 +731,7 @@ static enum sss_status sss_cli_check_socket(int *errno
             *errnop = error;
             break;
         case 0:
-            *errnop = ETIME;
+            *errnop = ETIMEDOUT;
             break;
         case 1:
             if (pfd.revents & (POLLERR | POLLHUP)) {
