--- fcgid_conf.c.orig	2007-07-31 04:09:20.000000000 -0500
+++ fcgid_conf.c	2007-10-08 08:17:12.000000000 -0500
@@ -17,8 +17,8 @@
 #define DEFAULT_ERROR_SCAN_INTERVAL 3
 #define DEFAULT_ZOMBIE_SCAN_INTERVAL 3
 #define DEFAULT_PROC_LIFETIME (60*60)
-#define DEFAULT_SOCKET_PREFIX "logs/fcgidsock"
-#define DEFAULT_SHM_PATH "logs/fcgid_shm"
+#define DEFAULT_SOCKET_PREFIX "/var/run/fcgidsock"
+#define DEFAULT_SHM_PATH "/var/run/fcgid_shm"
 #define DEFAULT_SPAWNSOCRE_UPLIMIT 10
 #define DEFAULT_SPAWN_SCORE 1
 #define DEFAULT_TERMINATION_SCORE 2
