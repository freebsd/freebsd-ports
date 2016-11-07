--- version/version.go.orig	2016-09-20 13:24:40 UTC
+++ version/version.go
@@ -10,8 +10,8 @@ var (
 	GitCommit   string
 	GitDescribe string
 
-	Version           = "unknown"
-	VersionPrerelease = "unknown"
+	Version           = "%%PORTVERSION%%"
+	VersionPrerelease = ""
 )
 
 // VersionInfo
