--- lib/common/BoxPortsAndFiles.h.orig	Thu Mar 16 19:28:09 2006
+++ lib/common/BoxPortsAndFiles.h	Thu Mar 16 19:28:38 2006
@@ -53,7 +53,7 @@
 
 // Backup store daemon
 #define BOX_PORT_BBSTORED					(BOX_PORT_BASE+1)
-#define BOX_FILE_BBSTORED_DEFAULT_CONFIG	"/etc/box/bbstored.conf"
+#define BOX_FILE_BBSTORED_DEFAULT_CONFIG	"%%PREFIX%%/etc/box/bbstored.conf"
 // directory within the RAIDFILE root for the backup store daemon
 #define BOX_RAIDFILE_ROOT_BBSTORED			"backup"
 
@@ -61,11 +61,11 @@
 #ifdef WIN32
 #define BOX_FILE_BBACKUPD_DEFAULT_CONFIG	"C:\\Program Files\\Box Backup\\bbackupd.conf"
 #else
-#define BOX_FILE_BBACKUPD_DEFAULT_CONFIG	"/etc/box/bbackupd.conf"
+#define BOX_FILE_BBACKUPD_DEFAULT_CONFIG	"%%PREFIX%%/etc/box/bbackupd.conf"
 #endif
 
 // RaidFile conf location default
-#define BOX_FILE_RAIDFILE_DEFAULT_CONFIG	"/etc/box/raidfile.conf"
+#define BOX_FILE_RAIDFILE_DEFAULT_CONFIG	"%%PREFIX%%/etc/box/raidfile.conf"
 
 // Default name of the named pipe
 #define BOX_NAMED_PIPE_NAME L"\\\\.\\pipe\\boxbackup"
