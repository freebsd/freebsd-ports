--- db/migrations.go.orig	2020-02-10 17:37:11 UTC
+++ db/migrations.go
@@ -9,7 +9,7 @@ import (
 	log "github.com/Sirupsen/logrus"
 )
 
-var dbAssets = packr.NewBox("./migrations")
+var dbAssets = packr.NewBox("/usr/local/share/semaphore")
 
 // CheckExists queries the database to see if a migration table with this version id exists already
 func (version *Version) CheckExists() (bool, error) {
