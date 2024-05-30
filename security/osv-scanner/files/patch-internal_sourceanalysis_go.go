--- internal/sourceanalysis/go.go.orig	2024-06-21 19:21:07.662367000 +0200
+++ internal/sourceanalysis/go.go	2024-06-21 19:21:27.715630000 +0200
@@ -18,7 +18,7 @@
 )
 
 func goAnalysis(r reporter.Reporter, pkgs []models.PackageVulns, source models.SourceInfo) {
-	cmd := exec.Command("go", "version")
+	cmd := exec.Command("go%%GO_SUFFIX%%", "version")
 	_, err := cmd.Output()
 	if err != nil {
 		r.Infof("Skipping call analysis on Go code since Go is not installed.\n")
