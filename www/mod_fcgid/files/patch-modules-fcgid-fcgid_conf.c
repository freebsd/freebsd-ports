--- modules/fcgid/fcgid_conf.c.orig	2009-10-07 05:16:08.000000000 +0200
+++ modules/fcgid/fcgid_conf.c	2009-12-11 16:18:09.000000000 +0100
@@ -35,8 +35,8 @@
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
