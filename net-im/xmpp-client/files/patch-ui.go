--- ui.go.orig	2015-07-15 22:37:17.187612000 +0200
+++ ui.go	2015-07-15 22:37:59.261081000 +0200
@@ -23,10 +23,10 @@
 	"time"
 
 	"github.com/agl/xmpp-client/xmpp"
-	"golang.org/x/crypto/otr"
-	"golang.org/x/crypto/ssh/terminal"
-	"golang.org/x/net/html"
-	"golang.org/x/net/proxy"
+	"code.google.com/p/go.crypto/otr"
+	"code.google.com/p/go.crypto/ssh/terminal"
+	"code.google.com/p/go.net/html"
+	"code.google.com/p/go.net/proxy"
 )
 
 var configFile *string = flag.String("config-file", "", "Location of the config file")
