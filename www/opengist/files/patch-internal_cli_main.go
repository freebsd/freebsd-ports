--- internal/cli/main.go.orig	1979-11-30 00:00:00 UTC
+++ internal/cli/main.go
@@ -92,12 +92,12 @@ func Initialize(ctx *cli.Context) {
 			"Current git version: " + gitVersion)
 	}
 
-	if err := git.InitGitConfig(); err != nil {
-		log.Fatal().Err(err).Send()
-	}
-
 	homePath := config.GetHomeDir()
 	log.Info().Msg("Data directory: " + homePath)
+
+	if err := git.InitGitConfig(); err != nil {
+		log.Warn().Msg("Git config modification failed, ensure " + homePath + " is added to git safe directories, and receive.advertisePushOptions is set to true.")
+	}
 
 	if err := createSymlink(homePath, ctx.String("config")); err != nil {
 		log.Fatal().Err(err).Msg("Failed to create symlinks")
