--- subcmds/saas.go.orig	1979-11-29 23:00:00 UTC
+++ subcmds/saas.go
@@ -46,7 +46,7 @@ func (p *SaaSCmd) SetFlags(f *flag.FlagSet) {
 	f.BoolVar(&config.Conf.Quiet, "quiet", false, "Quiet mode. No output on stdout")
 
 	wd, _ := os.Getwd()
-	defaultConfPath := filepath.Join(wd, "config.toml")
+	defaultConfPath := "%%ETCDIR%%/config.toml"
 	f.StringVar(&p.configPath, "config", defaultConfPath, "/path/to/toml")
 
 	defaultResultsDir := filepath.Join(wd, "results")
