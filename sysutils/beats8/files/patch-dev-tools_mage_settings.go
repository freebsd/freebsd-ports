--- dev-tools/mage/settings.go.orig	2026-08-26 15:33:57 UTC
+++ dev-tools/mage/settings.go
@@ -32,7 +32,6 @@ import (
 	"sync"
 	"time"
 
-	"github.com/magefile/mage/sh"
 	"golang.org/x/text/cases"
 	"golang.org/x/text/language"
 	"gopkg.in/yaml.v3"
@@ -280,7 +279,8 @@ func CommitHash() (string, error) {
 func CommitHash() (string, error) {
 	var err error
 	commitHashOnce.Do(func() {
-		commitHash, err = sh.Output("git", "rev-parse", "HEAD")
+		err = nil
+		commitHash = "%%BEATSVERSION%%"
 	})
 	return commitHash, err
 }
