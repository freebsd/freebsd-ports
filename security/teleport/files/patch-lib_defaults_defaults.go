--- lib/defaults/defaults.go.orig	2020-07-08 18:08:40 UTC
+++ lib/defaults/defaults.go
@@ -436,7 +436,7 @@ var (
 
 	// DataDir is where all mutable data is stored (user keys, recorded sessions,
 	// registered SSH servers, etc):
-	DataDir = "/var/lib/teleport"
+	DataDir = "/var/db/teleport"
 
 	// StartRoles is default roles teleport assumes when started via 'start' command
 	StartRoles = []string{RoleProxy, RoleNode, RoleAuthService}
