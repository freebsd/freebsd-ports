--- cmd/picoclaw/main.go.orig	1979-11-29 23:00:00 UTC
+++ cmd/picoclaw/main.go
@@ -28,7 +28,6 @@ import (
 	"github.com/sipeed/picoclaw/cmd/picoclaw/internal/status"
 	"github.com/sipeed/picoclaw/cmd/picoclaw/internal/version"
 	"github.com/sipeed/picoclaw/pkg/config"
-	"github.com/sipeed/picoclaw/pkg/updater"
 )
 
 var rootNoColor bool
@@ -94,7 +93,6 @@ picoclaw --no-color status`,
 		migrate.NewMigrateCommand(),
 		skills.NewSkillsCommand(),
 		model.NewModelCommand(),
-		updater.NewUpdateCommand("picoclaw"),
 		version.NewVersionCommand(),
 	)
 
