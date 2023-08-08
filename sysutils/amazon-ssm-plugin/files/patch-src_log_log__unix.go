--- src/log/log_unix.go.orig	2022-06-17 20:08:49 UTC
+++ src/log/log_unix.go
@@ -23,8 +23,8 @@ import (
 )
 
 const (
-	LogsDirectory                = "logs"
-	DefaultInstallLocationPrefix = "/usr/local"
+	DefaultLogsDirectory         = "%%LOGDIR%%"
+	DefaultInstallLocationPrefix = "%%ETCDIR%%"
 )
 
 func getApplicationName(clientName string) string {
@@ -45,7 +45,7 @@ func getLogConfigBytes(clientName string) (logConfigBy
 
 	applicationName := getApplicationName(clientName)
 	DefaultSeelogConfigFilePath = filepath.Join(DefaultInstallLocationPrefix, applicationName, SeelogConfigFileName)
-	DefaultLogDir = filepath.Join(DefaultInstallLocationPrefix, applicationName, LogsDirectory)
+	DefaultLogDir = filepath.Join(DefaultLogsDirectory, applicationName)
 	ApplicationLogFile = fmt.Sprintf("%s%s", clientName, LogFileExtension)
 	ErrorLogFile = fmt.Sprintf("%s%s", ErrorLogFileSuffix, LogFileExtension)
 	if logConfigBytes, err = ioutil.ReadFile(DefaultSeelogConfigFilePath); err != nil {
