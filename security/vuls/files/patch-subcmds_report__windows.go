--- subcmds/report_windows.go.orig	1979-11-29 23:00:00 UTC
+++ subcmds/report_windows.go
@@ -107,7 +107,7 @@ func (p *ReportCmd) SetFlags(f *flag.FlagSet) {
 	f.BoolVar(&config.Conf.NoProgress, "no-progress", false, "Suppress progress bar")
 
 	wd, _ := os.Getwd()
-	defaultConfPath := filepath.Join(wd, "config.toml")
+	defaultConfPath := "%%ETCDIR%%/config.toml"
 	f.StringVar(&p.configPath, "config", defaultConfPath, "/path/to/toml")
 
 	defaultResultsDir := filepath.Join(wd, "results")
