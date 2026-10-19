--- internal/theme/legacy_gtk.go.orig	2026-09-20 08:33:19 UTC
+++ internal/theme/legacy_gtk.go
@@ -19,7 +19,7 @@ func RetireLegacyGTKStylesheets() error {
 // versions without touching unrecognized files or existing backups.
 func RetireLegacyGTKStylesheets() error {
 	var errs []error
-	if runtime.GOOS == "linux" {
+	if runtime.GOOS == "linux" || runtime.GOOS == "freebsd" {
 		home, err := os.UserHomeDir()
 		if err != nil {
 			errs = append(errs, err)
