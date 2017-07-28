--- commands/scan.go.orig	2017-06-23 15:51:48 UTC
+++ commands/scan.go
@@ -82,18 +82,18 @@ func (*ScanCmd) Usage() string {
 func (p *ScanCmd) SetFlags(f *flag.FlagSet) {
 	f.BoolVar(&p.debug, "debug", false, "debug mode")
 
-	wd, _ := os.Getwd()
 
-	defaultConfPath := filepath.Join(wd, "config.toml")
+	defaultConfPath := "%%ETCDIR%%/config.toml"
 	f.StringVar(&p.configPath, "config", defaultConfPath, "/path/to/toml")
 
+	wd, _ := os.Getwd()
 	defaultResultsDir := filepath.Join(wd, "results")
 	f.StringVar(&p.resultsDir, "results-dir", defaultResultsDir, "/path/to/results")
 
 	defaultLogDir := util.GetDefaultLogDir()
 	f.StringVar(&p.logDir, "log-dir", defaultLogDir, "/path/to/log")
 
-	defaultCacheDBPath := filepath.Join(wd, "cache.db")
+	defaultCacheDBPath := "/var/db/vuls/cache.db"
 	f.StringVar(
 		&p.cacheDBPath,
 		"cachedb-path",
