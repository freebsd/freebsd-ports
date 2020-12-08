--- subcmds/report.go.orig	2020-11-27 21:39:52 UTC
+++ subcmds/report.go
@@ -108,10 +108,10 @@ func (p *ReportCmd) SetFlags(f *flag.FlagSet) {
 	f.BoolVar(&c.Conf.Quiet, "quiet", false, "Quiet mode. No output on stdout")
 	f.BoolVar(&c.Conf.NoProgress, "no-progress", false, "Suppress progress bar")
 
-	wd, _ := os.Getwd()
-	defaultConfPath := filepath.Join(wd, "config.toml")
+	defaultConfPath := filepath.Join("%%ETCDIR%%", "config.toml")
 	f.StringVar(&p.configPath, "config", defaultConfPath, "/path/to/toml")
 
+    wd, _ := os.Getwd()
 	defaultResultsDir := filepath.Join(wd, "results")
 	f.StringVar(&c.Conf.ResultsDir, "results-dir", defaultResultsDir, "/path/to/results")
 
@@ -177,7 +177,7 @@ func (p *ReportCmd) SetFlags(f *flag.FlagSet) {
 
 	f.StringVar(&p.cveDict.Type, "cvedb-type", "",
 		"DB type of go-cve-dictionary (sqlite3, mysql, postgres, redis or http)")
-	f.StringVar(&p.cveDict.SQLite3Path, "cvedb-sqlite3-path", "", "/path/to/sqlite3")
+	f.StringVar(&p.cveDict.SQLite3Path, "cvedb-sqlite3-path", "", "/var/db/vuls/cve.sqlite3")
 	f.StringVar(&p.cveDict.URL, "cvedb-url", "",
 		"http://go-cve-dictionary.com:1323 or DB connection string")
 
