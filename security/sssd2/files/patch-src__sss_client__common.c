--- src/sss_client/common.c.orig	2024-01-12 12:05:40 UTC
+++ src/sss_client/common.c
@@ -170,7 +170,7 @@ static enum sss_status sss_cli_send_req(enum sss_cli_c
             *errnop = error;
             break;
         case 0:
-            *errnop = ETIME;
+            *errnop = ETIMEDOUT;
             break;
         case 1:
             if (pfd.revents & (POLLERR | POLLHUP)) {
@@ -282,7 +282,7 @@ static enum sss_status sss_cli_recv_rep(enum sss_cli_c
             *errnop = error;
             break;
         case 0:
-            *errnop = ETIME;
+            *errnop = ETIMEDOUT;
             break;
         case 1:
             if (pfd.revents & (POLLHUP)) {
@@ -781,7 +781,7 @@ static enum sss_status sss_cli_check_socket(int *errno
             *errnop = error;
             break;
         case 0:
-            *errnop = ETIME;
+            *errnop = ETIMEDOUT;
             break;
         case 1:
             if (pfd.revents & (POLLERR | POLLHUP)) {
