--- modules/azuredevops/widget.go.orig	2019-10-11 19:16:00 UTC
+++ modules/azuredevops/widget.go
@@ -13,7 +13,7 @@ import (
 
 type Widget struct {
 	view.TextWidget
-	cli           azrBuild.Client
+	cli           *azrBuild.Client
 	settings      *Settings
 	displayBuffer string
 	ctx           context.Context
