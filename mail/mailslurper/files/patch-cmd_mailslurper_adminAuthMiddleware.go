--- cmd/mailslurper/adminAuthMiddleware.go.orig	2020-04-16 15:05:22 UTC
+++ cmd/mailslurper/adminAuthMiddleware.go
@@ -8,7 +8,7 @@ import (
 	"net/http"
 
 	"github.com/gorilla/sessions"
-	"github.com/labstack/echo"
+	"github.com/labstack/echo/v4"
 	"github.com/labstack/echo-contrib/session"
 	"github.com/mailslurper/mailslurper/pkg/auth/authscheme"
 	"github.com/mailslurper/mailslurper/pkg/contexts"
