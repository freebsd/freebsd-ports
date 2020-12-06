--- pkg/collector/corechecks/embed/apm_nix.go.orig	2020-11-23 14:42:53 UTC
+++ pkg/collector/corechecks/embed/apm_nix.go
@@ -23,7 +23,7 @@ const apm_binary_name = "trace-agent" //nolint:golint
 
 func getAPMAgentDefaultBinPath() (string, error) {
 	here, _ := executable.Folder()
-	binPath := filepath.Join(here, "..", "..", "embedded", "bin", apm_binary_name)
+	binPath := filepath.Join(here, apm_binary_name)
 	_, err := os.Stat(binPath)
 	if err == nil {
 		return binPath, nil
