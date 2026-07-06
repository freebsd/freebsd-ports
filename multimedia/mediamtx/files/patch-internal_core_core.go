--- internal/core/core.go.orig	2026-06-12 22:46:57 UTC
+++ internal/core/core.go
@@ -102,7 +102,7 @@ var cli struct {
 	Confpath     string `arg:"" default:""`
 	Version      bool   `help:"print version"`
 	CheckVersion bool   `help:"check whether a new version is available"`
-	Upgrade      bool   `help:"upgrade executable to the latest version"`
+//	Upgrade      bool   `help:"upgrade executable to the latest version"`
 }
 
 // Core is an instance of MediaMTX.
@@ -176,14 +176,14 @@ func New(args []string) (*Core, bool) {
 		os.Exit(0)
 	}
 
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
 
 	ctx, ctxCancel := context.WithCancel(context.Background())
 
