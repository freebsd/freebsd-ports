--- pkg/contexts/AdminUserContext.go.orig	2020-04-16 15:10:52 UTC
+++ pkg/contexts/AdminUserContext.go
@@ -4,7 +4,7 @@
 
 package contexts
 
-import "github.com/labstack/echo"
+import "github.com/labstack/echo/v4"
 
 type AdminUserContext struct {
 	echo.Context
