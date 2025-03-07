--- main.go.orig	2025-03-07 21:35:10 UTC
+++ main.go
@@ -7,8 +7,8 @@ var (
 )
 
 var (
-	version   = "dev"
-	buildTime = "unknown"
+	version   = "%%DISTVERSION%%"
+	buildTime = "%%BUILDTIME%%"
 )
 
 func main() {
