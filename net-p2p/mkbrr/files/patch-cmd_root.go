--- cmd/root.go.orig	2025-04-16 21:16:09 UTC
+++ cmd/root.go
@@ -23,7 +23,6 @@ func init() {
 	rootCmd.AddCommand(checkCmd)
 	rootCmd.AddCommand(inspectCmd)
 	rootCmd.AddCommand(modifyCmd)
-	rootCmd.AddCommand(updateCmd)
 	rootCmd.AddCommand(versionCmd)
 }
 
