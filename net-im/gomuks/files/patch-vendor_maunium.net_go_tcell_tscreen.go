--- vendor/maunium.net/go/tcell/tscreen.go.orig	2022-04-12 11:45:41 UTC
+++ vendor/maunium.net/go/tcell/tscreen.go
@@ -50,13 +50,9 @@ const (
 // $COLUMNS environment variables can be set to the actual window size,
 // otherwise defaults taken from the terminal database are used.
 func NewTerminfoScreen() (Screen, error) {
-	term := os.Getenv("TERM")
-	if len(term) >= 6 && term[:6] == "screen" && len(os.Getenv("TMUX")) > 0 {
-		term = "tmux"
-	}
-	ti, e := terminfo.LookupTerminfo(term)
+	ti, e := terminfo.LookupTerminfo(os.Getenv("TERM"))
 	if e != nil {
-		ti, e = loadDynamicTerminfo(term)
+		ti, e = loadDynamicTerminfo(os.Getenv("TERM"))
 		if e != nil {
 			return nil, e
 		}
