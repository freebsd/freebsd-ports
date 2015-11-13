--- config.go.orig	2015-07-15 22:34:06.825572000 +0200
+++ config.go	2015-07-15 22:36:21.406502000 +0200
@@ -12,9 +12,9 @@
 	"strings"
 
 	"github.com/agl/xmpp-client/xmpp"
-	"golang.org/x/crypto/otr"
-	"golang.org/x/crypto/ssh/terminal"
-	"golang.org/x/net/proxy"
+	"code.google.com/p/go.crypto/otr"
+	"code.google.com/p/go.crypto/ssh/terminal"
+	"code.google.com/p/go.net/proxy"
 )
 
 type Config struct {
