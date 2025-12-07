--- build/build.go.orig	2025-11-22 13:04:05 UTC
+++ build/build.go
@@ -1,13 +1,13 @@ package build
 package build
 
 // Version stores the current version of the app
-var Version = "development"
+var Version = "%%DISTVERSION%%"
 
 // Time of the build
-var Time string
+var Time = "%%BUILDTIME%%"
 
 // User who built it
-var User string
+var User = "%%BUILDUSER%%"
 
 // RootPathPrefix stores path to be prepended to given absolute path
 // e.g. /var/lib/snapd/hostfs for snap
