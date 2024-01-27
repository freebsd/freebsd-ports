--- subcmds/server.go.orig	1979-11-29 23:00:00 UTC
+++ subcmds/server.go
@@ -60,7 +60,7 @@ func (p *ServerCmd) SetFlags(f *flag.FlagSet) {
 	f.BoolVar(&config.Conf.DebugSQL, "debug-sql", false, "SQL debug mode")
 
 	wd, _ := os.Getwd()
-	defaultConfPath := filepath.Join(wd, "config.toml")
+	defaultConfPath := "%%ETCDIR%%/config.toml"
 	f.StringVar(&p.configPath, "config", defaultConfPath, "/path/to/toml")
 
 	defaultResultsDir := filepath.Join(wd, "results")
