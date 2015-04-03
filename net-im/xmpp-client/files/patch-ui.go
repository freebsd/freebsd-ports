--- ui.go.orig	2015-03-07 22:40:10.096733000 +0100
+++ ui.go	2015-03-07 22:41:07.136470000 +0100
@@ -22,10 +22,10 @@
 	"time"
 
 	"github.com/agl/xmpp"
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
