--- internal/sourceanalysis/go.go.orig	1979-11-29 23:00:00 UTC
+++ internal/sourceanalysis/go.go
@@ -18,7 +18,7 @@ func goAnalysis(r reporter.Reporter, pkgs []models.Pac
 )
 
 func goAnalysis(r reporter.Reporter, pkgs []models.PackageVulns, source models.SourceInfo) {
-	cmd := exec.Command("go", "version")
+	cmd := exec.Command("go%%GO_SUFFIX%%", "version")
 	_, err := cmd.Output()
 	if err != nil {
 		r.Infof("Skipping call analysis on Go code since Go is not installed.\n")
