--- vendor/github.com/jroimartin/gocui/keybinding.go.orig	2019-07-26 09:44:40 UTC
+++ vendor/github.com/jroimartin/gocui/keybinding.go
@@ -78,9 +78,9 @@ const (
 
 // Keys combinations.
 const (
-	KeyCtrlTilde      Key = Key(termbox.KeyCtrlTilde)
+//	KeyCtrlTilde      Key = Key(termbox.KeyCtrlTilde)
 	KeyCtrl2              = Key(termbox.KeyCtrl2)
-	KeyCtrlSpace          = Key(termbox.KeyCtrlSpace)
+//	KeyCtrlSpace          = Key(termbox.KeyCtrlSpace)
 	KeyCtrlA              = Key(termbox.KeyCtrlA)
 	KeyCtrlB              = Key(termbox.KeyCtrlB)
 	KeyCtrlC              = Key(termbox.KeyCtrlC)
@@ -123,7 +123,7 @@ const (
 	KeyCtrlUnderscore     = Key(termbox.KeyCtrlUnderscore)
 	KeySpace              = Key(termbox.KeySpace)
 	KeyBackspace2         = Key(termbox.KeyBackspace2)
-	KeyCtrl8              = Key(termbox.KeyCtrl8)
+//	KeyCtrl8              = Key(termbox.KeyCtrl8)
 )
 
 // Modifier allows to define special keys combinations. They can be used
