--- agent/appconfig/constants_unix.go.orig	2017-05-22 17:12:08.000000000 +0000
+++ agent/appconfig/constants_unix.go	2017-05-28 06:51:05.792117000 +0000
@@ -18,7 +18,7 @@
 
 const (
 	// DefaultProgramFolder is the default folder for SSM
-	DefaultProgramFolder = "/etc/amazon/ssm/"
+	DefaultProgramFolder = "/usr/local/etc/amazon/ssm/"
 
 	// AppConfigPath is the path of the AppConfig
 	AppConfigPath = DefaultProgramFolder + AppConfigFileName
@@ -47,7 +47,7 @@
 	DownloadRoot = "/var/log/amazon/ssm/download/"
 
 	// DefaultDataStorePath represents the directory for storing system data
-	DefaultDataStorePath = "/var/lib/amazon/ssm/"
+	DefaultDataStorePath = "/var/run/amazon/ssm/"
 
 	// EC2ConfigDataStorePath represents the directory for storing ec2 config data
 	EC2ConfigDataStorePath = "/var/lib/amazon/ec2config/"
