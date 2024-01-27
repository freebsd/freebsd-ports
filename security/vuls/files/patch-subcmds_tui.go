--- subcmds/tui.go.orig	1979-11-29 23:00:00 UTC
+++ subcmds/tui.go
@@ -72,7 +72,7 @@ func (p *TuiCmd) SetFlags(f *flag.FlagSet) {
 	defaultResultsDir := filepath.Join(wd, "results")
 	f.StringVar(&config.Conf.ResultsDir, "results-dir", defaultResultsDir, "/path/to/results")
 
-	defaultConfPath := filepath.Join(wd, "config.toml")
+	defaultConfPath := "%%ETCDIR%%/config.toml"
 	f.StringVar(&p.configPath, "config", defaultConfPath, "/path/to/toml")
 
 	f.BoolVar(&config.Conf.RefreshCve, "refresh-cve", false,
