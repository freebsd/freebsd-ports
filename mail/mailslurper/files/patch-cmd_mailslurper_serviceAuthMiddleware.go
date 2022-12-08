--- cmd/mailslurper/serviceAuthMiddleware.go.orig	2020-04-16 15:16:32 UTC
+++ cmd/mailslurper/serviceAuthMiddleware.go
@@ -9,7 +9,7 @@ import (
 	"strings"
 
 	jwt "github.com/dgrijalva/jwt-go"
-	"github.com/labstack/echo"
+	"github.com/labstack/echo/v4"
 	"github.com/mailslurper/mailslurper/pkg/auth/authscheme"
 	jwtservice "github.com/mailslurper/mailslurper/pkg/auth/jwt"
 	"github.com/mailslurper/mailslurper/pkg/contexts"
