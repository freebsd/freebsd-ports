--- pkg/ui/TemplateRenderer.go.orig	2020-04-16 15:11:45 UTC
+++ pkg/ui/TemplateRenderer.go
@@ -9,7 +9,7 @@ import (
 	"html/template"
 	"io"
 
-	"github.com/labstack/echo"
+	"github.com/labstack/echo/v4"
 
 	"github.com/mailslurper/mailslurper/cmd/mailslurper/www"
 )
