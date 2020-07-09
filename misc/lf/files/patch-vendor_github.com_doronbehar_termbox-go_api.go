Same as https://github.com/nsf/termbox-go/commit/58d4fcbc
Suggested in https://github.com/gokcehan/lf/issues/392#issuecomment-656045163

--- vendor/github.com/doronbehar/termbox-go/api.go.orig	2020-07-09 15:15:27 UTC
+++ vendor/github.com/doronbehar/termbox-go/api.go
@@ -24,7 +24,7 @@ import "time"
 func Init() error {
 	var err error
 
-	if runtime.GOOS == "openbsd" {
+	if runtime.GOOS == "openbsd" || runtime.GOOS == "freebsd" {
 		out, err = os.OpenFile("/dev/tty", os.O_RDWR, 0)
 		if err != nil {
 			return err
