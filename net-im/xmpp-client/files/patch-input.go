--- input.go.orig	2015-03-07 22:39:38.830132000 +0100
+++ input.go	2015-03-07 22:39:59.824941000 +0100
@@ -7,7 +7,7 @@
 	"strings"
 	"sync"
 
-	"golang.org/x/crypto/ssh/terminal"
+	"code.google.com/p/go.crypto/ssh/terminal"
 )
 
 type uiCommand struct {
