--- commands/report.go.orig	2018-11-16 12:22:18 UTC
+++ commands/report.go
@@ -110,10 +110,10 @@ func (p *ReportCmd) SetFlags(f *flag.Fla
 	f.BoolVar(&c.Conf.Debug, "debug", false, "debug mode")
 	f.BoolVar(&c.Conf.DebugSQL, "debug-sql", false, "SQL debug mode")
 
-	wd, _ := os.Getwd()
-	defaultConfPath := filepath.Join(wd, "config.toml")
+    defaultConfPath := "%%ETCDIR%%/config.toml"
 	f.StringVar(&p.configPath, "config", defaultConfPath, "/path/to/toml")
 
+	wd, _ := os.Getwd()
 	defaultResultsDir := filepath.Join(wd, "results")
 	f.StringVar(&c.Conf.ResultsDir, "results-dir", defaultResultsDir, "/path/to/results")
 
@@ -172,7 +172,7 @@ func (p *ReportCmd) SetFlags(f *flag.Fla
 
 	f.StringVar(&p.cveDict.Type, "cvedb-type", "",
 		"DB type of go-cve-dictionary (sqlite3, mysql, postgres, redis or http)")
-	f.StringVar(&p.cveDict.SQLite3Path, "cvedb-sqlite3-path", "", "/path/to/sqlite3")
+	f.StringVar(&p.cveDict.SQLite3Path, "cvedb-sqlite3-path", "", "/var/db/vuls/cve.sqlite3")
 	f.StringVar(&p.cveDict.URL, "cvedb-url", "",
 		"http://go-cve-dictionary.com:1323 or DB connection string")
 
