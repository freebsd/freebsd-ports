--- dev-tools/mage/settings.go.orig	2024-07-09 00:00:36.000000000 +0200
+++ dev-tools/mage/settings.go	2024-07-13 21:26:19.383768000 +0200
@@ -31,7 +31,6 @@
 	"sync"
 	"time"
 
-	"github.com/magefile/mage/sh"
 	"golang.org/x/tools/go/vcs"
 
 	"github.com/elastic/beats/v7/dev-tools/mage/gotool"
@@ -251,7 +250,8 @@
 func CommitHash() (string, error) {
 	var err error
 	commitHashOnce.Do(func() {
-		commitHash, err = sh.Output("git", "rev-parse", "HEAD")
+		err = nil
+		commitHash = "v8.14.3"
 	})
 	return commitHash, err
 }
