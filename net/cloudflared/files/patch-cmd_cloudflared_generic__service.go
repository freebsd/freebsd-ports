--- cmd/cloudflared/generic_service.go.orig	2026-10-30 16:43:29 UTC
+++ cmd/cloudflared/generic_service.go
@@ -11,6 +11,9 @@ import (
 	"github.com/cloudflare/cloudflared/cmd/cloudflared/cliutil"
 )
 
+// OS-specific function for token file creation
+var createTokenFile = createTokenFileUnix
+
 func runApp(app *cli.App, graceShutdownC chan struct{}) {
 	app.Commands = append(app.Commands, &cli.Command{
 		Name:  "service",
