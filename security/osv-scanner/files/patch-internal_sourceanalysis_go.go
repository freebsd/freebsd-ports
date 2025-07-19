--- internal/sourceanalysis/go.go.orig	1979-11-30 03:00:00 UTC
+++ internal/sourceanalysis/go.go
@@ -19,7 +19,7 @@ func goAnalysis(pkgs []models.PackageVulns, source mod
 )
 
 func goAnalysis(pkgs []models.PackageVulns, source models.SourceInfo) {
-	cmd := exec.Command("go", "version")
+	cmd := exec.Command("go%%GO_SUFFIX%%", "version")
 	_, err := cmd.Output()
 	if err != nil {
 		slog.Info("Skipping call analysis on Go code since Go is not installed.")
