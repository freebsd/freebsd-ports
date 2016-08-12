--- src/terminal.go.orig	2016-07-15 16:06:53 UTC
+++ src/terminal.go
@@ -15,7 +15,7 @@ import (
 	C "github.com/junegunn/fzf/src/curses"
 	"github.com/junegunn/fzf/src/util"
 
-	"github.com/junegunn/go-runewidth"
+	"github.com/mattn/go-runewidth"
 )
 
 type jumpMode int
