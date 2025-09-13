--- internal/sourceanalysis/go.go.orig	2025-09-13 17:59:56 UTC
+++ internal/sourceanalysis/go.go
@@ -21,7 +21,7 @@ func goAnalysis(pkgs []models.PackageVulns, source mod
 
 func goAnalysis(pkgs []models.PackageVulns, source models.SourceInfo) {
 	// TODO: This will be moved to enrichers which does have context.
-	cmd := exec.CommandContext(context.TODO(), "go", "version")
+	cmd := exec.CommandContext(context.TODO(), "go%%GO_SUFFIX%%", "version")
 	_, err := cmd.Output()
 	if err != nil {
 		cmdlogger.Infof("Skipping call analysis on Go code since Go is not installed.")
