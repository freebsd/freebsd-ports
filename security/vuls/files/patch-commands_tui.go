--- commands/tui.go.orig	2017-08-16 11:55:56 UTC
+++ commands/tui.go
@@ -107,12 +107,12 @@ func (p *TuiCmd) SetFlags(f *flag.FlagSe
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
