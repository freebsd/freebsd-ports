--- cmd/mailslurper/controllers/ServiceController.go.orig	2020-04-16 15:08:09 UTC
+++ cmd/mailslurper/controllers/ServiceController.go
@@ -11,7 +11,7 @@ import (
 	"strconv"
 	"time"
 
-	"github.com/labstack/echo"
+	"github.com/labstack/echo/v4"
 	"github.com/mailslurper/mailslurper/pkg/auth/auth"
 	"github.com/mailslurper/mailslurper/pkg/auth/authfactory"
 	"github.com/mailslurper/mailslurper/pkg/auth/jwt"
