--- usr/include/slotmgr.h.orig	2022-04-25 11:04:51 UTC
+++ usr/include/slotmgr.h
@@ -31,10 +31,10 @@
 #define TOK_PATH  SBIN_PATH "/pkcsslotd"
 #define OCK_API_LOCK_FILE LOCKDIR_PATH "/LCK..APIlock"
 
-#define PROC_SOCKET_FILE_PATH "/run/pkcsslotd.socket"
-#define ADMIN_SOCKET_FILE_PATH "/run/pkcsslotd.admin.socket"
+#define PROC_SOCKET_FILE_PATH "/var/run/pkcsslotd.socket"
+#define ADMIN_SOCKET_FILE_PATH "/var/run/pkcsslotd.admin.socket"
 
-#define PID_FILE_PATH "/run/pkcsslotd.pid"
+#define PID_FILE_PATH "/var/run/pkcsslotd.pid"
 #define OCK_CONFIG OCK_CONFDIR "/opencryptoki.conf"
 
 #ifndef CK_BOOL
