--- cmd/mailslurper/controllers/AdminController.go.orig	2020-04-16 15:07:36 UTC
+++ cmd/mailslurper/controllers/AdminController.go
@@ -9,7 +9,7 @@ import (
 	"sync"
 
 	"github.com/gorilla/sessions"
-	"github.com/labstack/echo"
+	"github.com/labstack/echo/v4"
 	"github.com/labstack/echo-contrib/session"
 	"github.com/mailslurper/mailslurper/pkg/auth/auth"
 	"github.com/mailslurper/mailslurper/pkg/auth/authfactory"
