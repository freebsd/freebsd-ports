--- cmd/mailslurper/setupServicesListener.go.orig	2020-04-16 15:09:13 UTC
+++ cmd/mailslurper/setupServicesListener.go
@@ -5,8 +5,8 @@
 package main
 
 import (
-	"github.com/labstack/echo"
-	"github.com/labstack/echo/middleware"
+	"github.com/labstack/echo/v4"
+	"github.com/labstack/echo/v4/middleware"
 	"github.com/mailslurper/mailslurper/cmd/mailslurper/controllers"
 	"github.com/mailslurper/mailslurper/pkg/auth/authfactory"
 	"github.com/mailslurper/mailslurper/pkg/auth/authscheme"
