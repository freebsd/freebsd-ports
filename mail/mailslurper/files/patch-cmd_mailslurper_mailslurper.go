--- cmd/mailslurper/mailslurper.go.orig	2020-04-17 09:31:57 UTC
+++ cmd/mailslurper/mailslurper.go
@@ -14,7 +14,7 @@ import (
 	"syscall"
 	"time"
 
-	"github.com/labstack/echo"
+	"github.com/labstack/echo/v4"
 	"github.com/mailslurper/mailslurper/pkg/mailslurper"
 	"github.com/mailslurper/mailslurper/pkg/ui"
 	"github.com/patrickmn/go-cache"
