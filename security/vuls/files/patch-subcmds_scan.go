--- subcmds/scan.go.orig	2020-11-27 21:39:52 UTC
+++ subcmds/scan.go
@@ -64,8 +64,8 @@ func (p *ScanCmd) SetFlags(f *flag.FlagSet) {
 	f.BoolVar(&c.Conf.Debug, "debug", false, "debug mode")
 	f.BoolVar(&c.Conf.Quiet, "quiet", false, "Quiet mode. No output on stdout")
 
-	wd, _ := os.Getwd()
-	defaultConfPath := filepath.Join(wd, "config.toml")
+    wd, _ := os.Getwd()
+	defaultConfPath := filepath.Join("%%ETCDIR%%", "config.toml")
 	f.StringVar(&p.configPath, "config", defaultConfPath, "/path/to/toml")
 
 	defaultResultsDir := filepath.Join(wd, "results")
@@ -74,7 +74,7 @@ func (p *ScanCmd) SetFlags(f *flag.FlagSet) {
 	defaultLogDir := util.GetDefaultLogDir()
 	f.StringVar(&c.Conf.LogDir, "log-dir", defaultLogDir, "/path/to/log")
 
-	defaultCacheDBPath := filepath.Join(wd, "cache.db")
+	defaultCacheDBPath := "/var/db/vuls/cache.db"
 	f.StringVar(&c.Conf.CacheDBPath, "cachedb-path", defaultCacheDBPath,
 		"/path/to/cache.db (local cache of changelog for Ubuntu/Debian)")
 
