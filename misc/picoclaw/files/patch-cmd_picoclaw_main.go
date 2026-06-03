--- cmd/picoclaw/main.go.orig	2026-05-22 08:53:26 UTC
+++ cmd/picoclaw/main.go
@@ -27,7 +27,6 @@ import (
 	"github.com/sipeed/picoclaw/cmd/picoclaw/internal/status"
 	"github.com/sipeed/picoclaw/cmd/picoclaw/internal/version"
 	"github.com/sipeed/picoclaw/pkg/config"
-	"github.com/sipeed/picoclaw/pkg/updater"
 )
 
 var rootNoColor bool
@@ -92,7 +91,6 @@ picoclaw --no-color status`,
 		migrate.NewMigrateCommand(),
 		skills.NewSkillsCommand(),
 		model.NewModelCommand(),
-		updater.NewUpdateCommand("picoclaw"),
 		version.NewVersionCommand(),
 	)
 
