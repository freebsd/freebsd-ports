--- config/config.go.orig	2020-10-09 15:05:21 UTC
+++ config/config.go
@@ -17,7 +17,7 @@ import (
 var (
 	prefix        = "screego"
 	files         = []string{"screego.config.development.local", "screego.config.development", "screego.config.local", "screego.config"}
-	absoluteFiles = []string{"/etc/screego/server.config"}
+	absoluteFiles = []string{"%%ETCDIR%%/server.config"}
 	osExecutable  = os.Executable
 	osStat        = os.Stat
 )
