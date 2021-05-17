--- common/config/dirs.go.orig	2021-05-06 12:02:02 UTC
+++ common/config/dirs.go
@@ -54,9 +54,14 @@ func ApplicationWorkingDir(dirType ...ApplicationDirTy
 	} else if d == ApplicationDirServices && os.Getenv("CELLS_SERVICES_DIR") != "" {
 		f = os.Getenv("CELLS_SERVICES_DIR")
 	} else {
-		vendor := "Pydio"
-		if runtime.GOOS == "linux" {
+		// Pull request upstream:
+		// https://github.com/pydio/cells/pull/326
+		var vendor string
+		switch runtime.GOOS {
+		case "linux", "freebsd":
 			vendor = "pydio"
+		default:
+			vendor = "Pydio"
 		}
 		appName := "cells"
 		configDirs := configdir.New(vendor, appName)
