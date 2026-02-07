--- subcmds/scan.go.orig	1979-11-29 23:00:00 UTC
+++ subcmds/scan.go
@@ -61,7 +61,7 @@ func (p *ScanCmd) SetFlags(f *flag.FlagSet) {
 	f.BoolVar(&config.Conf.Quiet, "quiet", false, "Quiet mode. No output on stdout")
 
 	wd, _ := os.Getwd()
-	defaultConfPath := filepath.Join(wd, "config.toml")
+	defaultConfPath := "%%ETCDIR%%/config.toml"
 	f.StringVar(&p.configPath, "config", defaultConfPath, "/path/to/toml")
 
 	defaultResultsDir := filepath.Join(wd, "results")
