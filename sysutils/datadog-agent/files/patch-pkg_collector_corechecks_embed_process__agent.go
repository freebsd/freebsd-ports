--- pkg/collector/corechecks/embed/process_agent.go.orig	2020-11-23 17:16:28 UTC
+++ pkg/collector/corechecks/embed/process_agent.go
@@ -216,7 +216,7 @@ func init() {
 
 func getProcessAgentDefaultBinPath() (string, error) {
 	here, _ := executable.Folder()
-	binPath := filepath.Join(here, "..", "..", "embedded", "bin", "process-agent")
+	binPath := filepath.Join(here, "process-agent")
 	if _, err := os.Stat(binPath); err == nil {
 		return binPath, nil
 	}
