--- commands/scan.go.orig	2018-11-16 12:22:18 UTC
+++ commands/scan.go
@@ -75,17 +75,17 @@ func (*ScanCmd) Usage() string {
 func (p *ScanCmd) SetFlags(f *flag.FlagSet) {
 	f.BoolVar(&c.Conf.Debug, "debug", false, "debug mode")
 
-	wd, _ := os.Getwd()
-	defaultConfPath := filepath.Join(wd, "config.toml")
+    defaultConfPath := "%%ETCDIR%%/config.toml"
 	f.StringVar(&p.configPath, "config", defaultConfPath, "/path/to/toml")
 
+	wd, _ := os.Getwd()
 	defaultResultsDir := filepath.Join(wd, "results")
 	f.StringVar(&c.Conf.ResultsDir, "results-dir", defaultResultsDir, "/path/to/results")
 
 	defaultLogDir := util.GetDefaultLogDir()
 	f.StringVar(&c.Conf.LogDir, "log-dir", defaultLogDir, "/path/to/log")
 
-	defaultCacheDBPath := filepath.Join(wd, "cache.db")
+    defaultCacheDBPath := "/var/db/vuls/cache.db"
 	f.StringVar(&c.Conf.CacheDBPath, "cachedb-path", defaultCacheDBPath,
 		"/path/to/cache.db (local cache of changelog for Ubuntu/Debian)")
 
