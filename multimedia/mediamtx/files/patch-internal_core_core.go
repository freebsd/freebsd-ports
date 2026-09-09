--- internal/core/core.go.orig	2026-09-06 07:05:41 UTC
+++ internal/core/core.go
@@ -38,7 +38,7 @@ import (
 	"github.com/bluenviron/mediamtx/internal/servers/rtsp"
 	"github.com/bluenviron/mediamtx/internal/servers/srt"
 	"github.com/bluenviron/mediamtx/internal/servers/webrtc"
-	"github.com/bluenviron/mediamtx/internal/upgrade"
+//	"github.com/bluenviron/mediamtx/internal/upgrade"
 )
 
 //go:generate go run ./versiongetter
@@ -162,8 +162,8 @@ var cli struct {
 var cli struct {
 	Confpath     string `arg:"" default:""`
 	Version      bool   `help:"print version"`
-	CheckVersion bool   `help:"check whether a new version is available"`
-	Upgrade      bool   `help:"upgrade executable to the latest version"`
+//	CheckVersion bool   `help:"check whether a new version is available"`
+//	Upgrade      bool   `help:"upgrade executable to the latest version"`
 	ValidateConf string `help:"check whether a configuration file is valid" placeholder:"path"`
 }
 
@@ -263,17 +263,17 @@ func New(args []string) (*Core, bool) {
 	if cli.Version {
 		oneShotCount++
 	}
-	if cli.CheckVersion {
-		oneShotCount++
-	}
-	if cli.Upgrade {
-		oneShotCount++
-	}
+//	if cli.CheckVersion {
+//		oneShotCount++
+//	}
+//	if cli.Upgrade {
+//		oneShotCount++
+//	}
 	if cli.ValidateConf != "" {
 		oneShotCount++
 	}
 	if oneShotCount > 1 {
-		fmt.Printf("ERR: %v\n", "only one of --version, --check-version, --upgrade and --validate-conf can be used at a time")
+		fmt.Printf("ERR: %v\n", "only one of --version and --validate-conf can be used at a time")
 		return nil, false
 	}
 
@@ -282,27 +282,27 @@ func New(args []string) (*Core, bool) {
 		os.Exit(0)
 	}
 
-	if cli.CheckVersion {
-		var newVersionAvailable bool
-		newVersionAvailable, err = upgrade.CheckVersion(string(version), getArch())
-		if err != nil {
-			fmt.Printf("ERR: %v\n", err)
-			os.Exit(1)
-		}
-		if newVersionAvailable {
-			os.Exit(2)
-		}
-		os.Exit(0)
-	}
+//	if cli.CheckVersion {
+//		var newVersionAvailable bool
+//		newVersionAvailable, err = upgrade.CheckVersion(string(version), getArch())
+//		if err != nil {
+//			fmt.Printf("ERR: %v\n", err)
+//			os.Exit(1)
+//		}
+//		if newVersionAvailable {
+//			os.Exit(2)
+//		}
+//		os.Exit(0)
+//	}
 
-	if cli.Upgrade {
-		err = upgrade.Upgrade(string(version), getArch())
-		if err != nil {
-			fmt.Printf("ERR: %v\n", err)
-			os.Exit(1)
-		}
-		os.Exit(0)
-	}
+//	if cli.Upgrade {
+//		err = upgrade.Upgrade(string(version), getArch())
+//		if err != nil {
+//			fmt.Printf("ERR: %v\n", err)
+//			os.Exit(1)
+//		}
+//		os.Exit(0)
+//	}
 
 	if cli.ValidateConf != "" {
 		ok := validateConf(cli.ValidateConf)
