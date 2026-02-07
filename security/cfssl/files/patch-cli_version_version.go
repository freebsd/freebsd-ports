--- cli/version/version.go.orig	2020-05-23 09:19:37 UTC
+++ cli/version/version.go
@@ -9,7 +9,7 @@ import (
 )
 
 var (
-	version = "dev"
+	version = "%%DISTVERSION%%"
 )
 
 // Usage text for 'cfssl version'
