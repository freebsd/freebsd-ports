--- config.go.orig	2016-01-13 19:22:20 UTC
+++ config.go
@@ -14,7 +14,7 @@ import (
 	"github.com/agl/xmpp-client/xmpp"
 	"golang.org/x/crypto/otr"
 	"golang.org/x/crypto/ssh/terminal"
-	"golang.org/x/net/proxy"
+	"code.google.com/p/go.net/proxy"
 )
 
 type Config struct {
