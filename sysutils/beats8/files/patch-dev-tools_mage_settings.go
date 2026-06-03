--- dev-tools/mage/settings.go.orig	2025-09-15 19:57:17 UTC
+++ dev-tools/mage/settings.go
@@ -31,7 +31,6 @@ import (
 	"sync"
 	"time"
 
-	"github.com/magefile/mage/sh"
 	"golang.org/x/text/cases"
 	"golang.org/x/text/language"
 	"gopkg.in/yaml.v3"
@@ -282,7 +281,8 @@ func CommitHash() (string, error) {
 func CommitHash() (string, error) {
 	var err error
 	commitHashOnce.Do(func() {
-		commitHash, err = sh.Output("git", "rev-parse", "HEAD")
+		err = nil
+		commitHash = "%%BEATSVERSION%%"
 	})
 	return commitHash, err
 }
