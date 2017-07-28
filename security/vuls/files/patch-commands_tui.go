--- commands/tui.go.orig	2017-06-23 15:51:48 UTC
+++ commands/tui.go
@@ -94,12 +94,12 @@ func (p *TuiCmd) SetFlags(f *flag.FlagSe
 		"sqlite3",
 		"DB type for fetching CVE dictionary (sqlite3, mysql or postgres)")
 
-	defaultCveDBPath := filepath.Join(wd, "cve.sqlite3")
+	defaultCveDBPath := "/var/db/vuls/cve.sqlite3"
 	f.StringVar(
 		&p.cvedbpath,
 		"cvedb-path",
 		defaultCveDBPath,
-		"/path/to/sqlite3 (For get cve detail from cve.sqlite3)")
+		"/path/to/sqlite3 (For getting CVE details from cve.sqlite3)")
 
 	f.StringVar(
 		&p.cveDictionaryURL,
@@ -153,7 +153,7 @@ func (p *TuiCmd) Execute(_ context.Conte
 		if p.refreshCve || needToRefreshCve(r) {
 			if c.Conf.CveDBType == "sqlite3" {
 				if _, err := os.Stat(c.Conf.CveDBPath); os.IsNotExist(err) {
-					log.Errorf("SQLite3 DB(CVE-Dictionary) is not exist: %s",
+					log.Errorf("SQLite3 DB(CVE-Dictionary) does not exist: %s",
 						c.Conf.CveDBPath)
 					return subcommands.ExitFailure
 				}
