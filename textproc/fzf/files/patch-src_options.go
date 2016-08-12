--- src/options.go.orig	2016-08-08 11:09:38 UTC
+++ src/options.go
@@ -10,7 +10,7 @@ import (
 
 	"github.com/junegunn/fzf/src/curses"
 
-	"github.com/junegunn/go-shellwords"
+	"github.com/mattn/go-shellwords"
 )
 
 const usage = `usage: fzf [options]
