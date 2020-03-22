--- vendor/github.com/jroimartin/gocui/gui.go.orig	2019-07-26 09:44:40 UTC
+++ vendor/github.com/jroimartin/gocui/gui.go
@@ -115,11 +115,7 @@ func (g *Gui) SetRune(x, y int, ch rune, fgColor, bgCo
 // Rune returns the rune contained in the cell at the given position.
 // It checks if the position is valid.
 func (g *Gui) Rune(x, y int) (rune, error) {
-	if x < 0 || y < 0 || x >= g.maxX || y >= g.maxY {
-		return ' ', errors.New("invalid point")
-	}
-	c := termbox.CellBuffer()[y*g.maxX+x]
-	return c.Ch, nil
+	return ' ', errors.New("unimplemented")
 }
 
 // SetView creates a new view with its top-left corner at (x0, y0)
