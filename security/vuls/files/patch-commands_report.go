--- commands/report.go.orig	2017-06-23 15:51:48 UTC
+++ commands/report.go
@@ -132,11 +132,11 @@ func (p *ReportCmd) SetFlags(f *flag.Fla
 	f.BoolVar(&p.debug, "debug", false, "debug mode")
 	f.BoolVar(&p.debugSQL, "debug-sql", false, "SQL debug mode")
 
-	wd, _ := os.Getwd()
 
-	defaultConfPath := filepath.Join(wd, "config.toml")
+	defaultConfPath := "%%ETCDIR%%/config.toml"
 	f.StringVar(&p.configPath, "config", defaultConfPath, "/path/to/toml")
 
+	wd, _ := os.Getwd()
 	defaultResultsDir := filepath.Join(wd, "results")
 	f.StringVar(&p.resultsDir, "results-dir", defaultResultsDir, "/path/to/results")
 
@@ -155,7 +155,7 @@ func (p *ReportCmd) SetFlags(f *flag.Fla
 		"sqlite3",
 		"DB type for fetching CVE dictionary (sqlite3, mysql or postgres)")
 
-	defaultCveDBPath := filepath.Join(wd, "cve.sqlite3")
+	defaultCveDBPath := "/var/db/vuls/cve.sqlite3"
 	f.StringVar(
 		&p.cvedbpath,
 		"cvedb-path",
