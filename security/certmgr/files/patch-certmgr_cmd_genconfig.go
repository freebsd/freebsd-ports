--- certmgr/cmd/genconfig.go.orig	2021-07-04 20:59:28 UTC
+++ certmgr/cmd/genconfig.go
@@ -15,9 +15,9 @@ import (
 var force bool
 
 const (
-	defaultConfigFile     = "/etc/certmgr/certmgr.yaml"
-	defaultDir            = "/etc/certmgr.d"
-	defaultServiceManager = "systemd"
+	defaultConfigFile     = "%%ETCDIR%%/certmgr.yaml"
+	defaultDir            = "%%ETCDIR%%.d"
+	defaultServiceManager = "sysv"
 	defaultBefore         = "72h"
 	defaultInterval       = "1h"
 	defaultMetricsAddr    = "localhost"
