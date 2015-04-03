--- config.go.orig	2015-03-07 22:36:57.219206000 +0100
+++ config.go	2015-03-07 22:39:28.246637000 +0100
@@ -12,9 +12,9 @@
 	"strings"
 
 	"github.com/agl/xmpp"
-	"golang.org/x/crypto/otr"
-	"golang.org/x/crypto/ssh/terminal"
-	"golang.org/x/net/proxy"
+	"code.google.com/p/go.crypto/otr"
+	"code.google.com/p/go.crypto/ssh/terminal"
+	"code.google.com/p/go.net/proxy"
 )
 
 type Config struct {
