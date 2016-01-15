--- ui.go.orig	2016-01-13 19:21:21 UTC
+++ ui.go
@@ -26,8 +26,8 @@ import (
 	"github.com/agl/xmpp-client/xmpp"
 	"golang.org/x/crypto/otr"
 	"golang.org/x/crypto/ssh/terminal"
-	"golang.org/x/net/html"
-	"golang.org/x/net/proxy"
+	"code.google.com/p/go.net/html"
+	"code.google.com/p/go.net/proxy"
 )
 
 var configFile *string = flag.String("config-file", "", "Location of the config file")
