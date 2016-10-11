--- agent/log/log_unix.go.orig	2016-07-06 21:51:35 UTC
+++ agent/log/log_unix.go
@@ -24,7 +24,7 @@ const (
 	// DefaultSeelogConfigFilePath specifies the default seelog location
 	// The underlying logger is based of https://github.com/cihub/seelog
 	// See Seelog documentation to customize the logger
-	DefaultSeelogConfigFilePath = "/etc/amazon/ssm/seelog.xml"
+	DefaultSeelogConfigFilePath = "/usr/local/etc/amazon/ssm/seelog.xml"
 
 	DefaultLogDir = "/var/log/amazon/ssm"
 )
