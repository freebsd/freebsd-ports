--- channels/app/limits.go.orig	2026-05-26 04:10:36 UTC
+++ channels/app/limits.go
@@ -10,8 +10,8 @@ const (
 )
 
 const (
-	maxUsersLimit     = 200
-	maxUsersHardLimit = 250
+	maxUsersLimit     = 2_500
+	maxUsersHardLimit = 5_000
 )
 
 func (a *App) GetServerLimits() (*model.ServerLimits, *model.AppError) {
