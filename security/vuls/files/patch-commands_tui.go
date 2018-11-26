--- commands/tui.go.orig	2018-11-16 12:22:18 UTC
+++ commands/tui.go
@@ -116,7 +116,7 @@ func (p *TuiCmd) SetFlags(f *flag.FlagSe
 
 	f.StringVar(&p.cveDict.Type, "cvedb-type", "",
 		"DB type of go-cve-dictionary (sqlite3, mysql, postgres or redis)")
-	f.StringVar(&p.cveDict.SQLite3Path, "cvedb-path", "", "/path/to/sqlite3")
+	f.StringVar(&p.cveDict.SQLite3Path, "cvedb-path", "", "/var/db/vuls/cve.sqlite3")
 	f.StringVar(&p.cveDict.URL, "cvedb-url", "",
 		"http://go-cve-dictionary.com:1323 or DB connection string")
 
