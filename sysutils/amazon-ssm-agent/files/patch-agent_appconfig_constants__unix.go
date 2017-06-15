--- agent/appconfig/constants_unix.go.orig	2016-07-06 21:51:35 UTC
+++ agent/appconfig/constants_unix.go
@@ -18,7 +18,7 @@ package appconfig
 
 const (
 	// Program Folder
-	DefaultProgramFolder = "/etc/amazon/ssm/"
+	DefaultProgramFolder = "/usr/local/etc/amazon/ssm/"
 
 	// AppConfig Path
 	AppConfigPath = DefaultProgramFolder + AppConfigFileName
@@ -27,7 +27,7 @@ const (
 	DownloadRoot = "/var/log/amazon/ssm/download/"
 
 	// DefaultDataStorePath represents the directory for storing system data
-	DefaultDataStorePath = "/var/lib/amazon/ssm/"
+	DefaultDataStorePath = "/var/run/amazon/ssm/"
 
 	// UpdaterArtifactsRoot represents the directory for storing update related information
 	UpdaterArtifactsRoot = "/var/lib/amazon/ssm/update/"
