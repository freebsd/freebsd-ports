--- cmd/version/generate.go.orig	2025-08-28 00:13:15 UTC
+++ cmd/version/generate.go
@@ -8,7 +8,6 @@ import (
 	"io"
 	"io/fs"
 	"os"
-	"os/exec"
 	"path"
 	"path/filepath"
 	"runtime"
@@ -74,11 +73,7 @@ func getGitCommitHash(basePath string) (string, error)
 }
 
 func getGitCommitHash(basePath string) (string, error) {
-	cmd := exec.Command("git", "-C", basePath, "rev-parse", "HEAD")
-	commitHash, err := cmd.Output()
-	if err != nil {
-		return "", err
-	}
+	commitHash := "%%GITID%%"
 
 	return strings.TrimRight(string(commitHash), "\r\n"), nil
 }
