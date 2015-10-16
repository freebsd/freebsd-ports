--- input.go.orig	2015-07-15 22:36:40.838076000 +0200
+++ input.go	2015-07-15 22:36:50.956305000 +0200
@@ -7,7 +7,7 @@
 	"strings"
 	"sync"
 
-	"golang.org/x/crypto/ssh/terminal"
+	"code.google.com/p/go.crypto/ssh/terminal"
 )
 
 type uiCommand struct {
