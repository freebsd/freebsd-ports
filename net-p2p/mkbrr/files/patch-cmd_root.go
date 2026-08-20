--- cmd/root.go.orig	2026-08-19 18:38:38 UTC
+++ cmd/root.go
@@ -24,7 +24,6 @@ func init() {
 	rootCmd.AddCommand(inspectCmd)
 	rootCmd.AddCommand(modifyCmd)
 	rootCmd.AddCommand(updateTorrentCmd)
-	rootCmd.AddCommand(updateCmd)
 	rootCmd.AddCommand(versionCmd)
 }
 
