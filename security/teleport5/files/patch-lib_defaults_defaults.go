--- lib/defaults/defaults.go.orig	2022-02-23 04:58:43 UTC
+++ lib/defaults/defaults.go
@@ -466,7 +466,7 @@ var (
 
 	// DataDir is where all mutable data is stored (user keys, recorded sessions,
 	// registered SSH servers, etc):
-	DataDir = "/var/lib/teleport"
+	DataDir = "/var/db/teleport"
 
 	// StartRoles is default roles teleport assumes when started via 'start' command
 	StartRoles = []string{RoleProxy, RoleNode, RoleAuthService}
