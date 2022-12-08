--- cmd/mailslurper/setupAdminListener.go.orig	2020-04-16 15:08:53 UTC
+++ cmd/mailslurper/setupAdminListener.go
@@ -9,7 +9,7 @@ import (
 	"sync"
 
 	"github.com/gorilla/sessions"
-	"github.com/labstack/echo"
+	"github.com/labstack/echo/v4"
 	"github.com/labstack/echo-contrib/session"
 	"github.com/mailslurper/mailslurper/cmd/mailslurper/controllers"
 	"github.com/mailslurper/mailslurper/cmd/mailslurper/www"
