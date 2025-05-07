--- config/config.go.orig	2025-05-06 11:09:55.069815000 +0000
+++ config/config.go	2025-05-06 11:10:17.098859000 +0000
@@ -481,12 +481,12 @@
 // Try to find a default config file at these locations (in order):
 //  1. $TELEGRAF_CONFIG_PATH
 //  2. $HOME/.telegraf/telegraf.conf
-//  3. /etc/telegraf/telegraf.conf and /etc/telegraf/telegraf.d/*.conf
+//  3. /usr/local/etc/telegraf/telegraf.conf and /etc/telegraf/telegraf.d/*.conf
 func GetDefaultConfigPath() ([]string, error) {
 	envfile := os.Getenv("TELEGRAF_CONFIG_PATH")
 	homefile := os.ExpandEnv("${HOME}/.telegraf/telegraf.conf")
-	etcfile := "/etc/telegraf/telegraf.conf"
-	etcfolder := "/etc/telegraf/telegraf.d"
+	etcfile := "/usr/local/etc/telegraf/telegraf.conf"
+	etcfolder := "/usr/local/etc/telegraf/telegraf.d"
 
 	if runtime.GOOS == "windows" {
 		programFiles := os.Getenv("ProgramFiles")
