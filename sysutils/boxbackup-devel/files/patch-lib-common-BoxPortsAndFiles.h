--- lib/common/BoxPortsAndFiles.h.orig	Sat Jan  8 13:30:04 2005
+++ lib/common/BoxPortsAndFiles.h	Sat Jan  8 13:31:40 2005
@@ -54,16 +54,16 @@
 
 // Backup store daemon
 #define BOX_PORT_BBSTORED					(BOX_PORT_BASE+1)
-#define BOX_FILE_BBSTORED_DEFAULT_CONFIG	"/etc/box/bbstored.conf"
+#define BOX_FILE_BBSTORED_DEFAULT_CONFIG	"%%PREFIX%%/etc/box/bbstored.conf"
 // directory within the RAIDFILE root for the backup store daemon
 #define BOX_RAIDFILE_ROOT_BBSTORED			"backup"
 
 // Backup client daemon
-#define BOX_FILE_BBACKUPD_DEFAULT_CONFIG	"/etc/box/bbackupd.conf"
+#define BOX_FILE_BBACKUPD_DEFAULT_CONFIG	"%%PREFIX%%/etc/box/bbackupd.conf"
 
 
 // RaidFile conf location efault
-#define BOX_FILE_RAIDFILE_DEFAULT_CONFIG	"/etc/box/raidfile.conf"
+#define BOX_FILE_RAIDFILE_DEFAULT_CONFIG	"%%PREFIX%%/etc/box/raidfile.conf"
 
 
 #endif // BOXPORTSANDFILES__H
