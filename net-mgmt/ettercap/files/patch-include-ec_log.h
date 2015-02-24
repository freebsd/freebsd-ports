Obtained from:	https://github.com/Ettercap/ettercap/commit/42600aada0ba56b9c63dabcc2b0cb1417fa27863

--- include/ec_log.h.orig	2014-10-17 01:29:44.000000000 +0800
+++ include/ec_log.h	2015-02-21 19:58:20.730805519 +0800
@@ -8,6 +8,7 @@
 
 #include <zlib.h>
 #include <sys/time.h>
+#include <unistd.h>
 
 
 struct log_fd {
@@ -126,6 +127,8 @@
 #define LOG_TRUE     1
 #define LOG_FALSE    0
 
+EC_API_EXTERN void reset_logfile_owners(uid_t old_uid, gid_t old_gid, uid_t new_uid, gid_t new_gid);
+
 EC_API_EXTERN int log_open(struct log_fd *fd, char *filename);
 EC_API_EXTERN void log_close(struct log_fd *fd);
 EC_API_EXTERN void log_stop(void);
