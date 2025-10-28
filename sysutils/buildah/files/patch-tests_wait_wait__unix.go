--- tests/wait/wait_unix.go.orig	2025-10-17 18:57:49 UTC
+++ tests/wait/wait_unix.go
@@ -12,10 +12,6 @@ func main() {
 )
 
 func main() {
-	if err := unix.Prctl(unix.PR_SET_CHILD_SUBREAPER, uintptr(1), 0, 0, 0); err != nil {
-		fmt.Fprintf(os.Stderr, "%v", err)
-		os.Exit(1)
-	}
 	if len(os.Args) < 2 {
 		fmt.Fprintf(os.Stderr, "usage: %s [CMD ...]\n", filepath.Base(os.Args[0]))
 		os.Exit(1)
