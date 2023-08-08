--- dev-tools/mage/settings.go.orig	2022-09-27 13:19:27 UTC
+++ dev-tools/mage/settings.go
@@ -30,7 +30,6 @@ import (
 	"sync"
 	"time"
 
-	"github.com/magefile/mage/sh"
 	"github.com/pkg/errors"
 	"golang.org/x/tools/go/vcs"
 
@@ -249,7 +248,8 @@ var (
 func CommitHash() (string, error) {
 	var err error
 	commitHashOnce.Do(func() {
-		commitHash, err = sh.Output("git", "rev-parse", "HEAD")
+		err = nil
+		commitHash = "%%BEATSVERSION%%"
 	})
 	return commitHash, err
 }
