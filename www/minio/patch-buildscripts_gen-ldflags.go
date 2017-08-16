--- buildscripts/gen-ldflags.go.orig	2017-08-04 23:51:20 UTC
+++ buildscripts/gen-ldflags.go
@@ -23,15 +23,14 @@ import (
 	"os"
 	"os/exec"
 	"strings"
-	"time"
 )
 
 func genLDFlags(version string) string {
 	ldflagsStr := "-s -w"
-	ldflagsStr += " -X github.com/minio/minio/cmd.Version=" + version
-	ldflagsStr += " -X github.com/minio/minio/cmd.ReleaseTag=" + releaseTag(version)
-	ldflagsStr += " -X github.com/minio/minio/cmd.CommitID=" + commitID()
-	ldflagsStr += " -X github.com/minio/minio/cmd.ShortCommitID=" + commitID()[:12]
+	ldflagsStr += " -X github.com/minio/minio/cmd.Version=2017-08-05T00:00:53Z"
+	ldflagsStr += " -X github.com/minio/minio/cmd.ReleaseTag=RELEASE.2017-08-05T00-00-53Z"
+	ldflagsStr += " -X github.com/minio/minio/cmd.CommitID=aeafe668d8b6d25caac671d59e2b0f0473ce35d0"
+	ldflagsStr += " -X github.com/minio/minio/cmd.ShortCommitID=aeafe668d8b6d"
 	ldflagsStr += " -X github.com/minio/minio/cmd.GOPATH=" + os.Getenv("GOPATH")
 	return ldflagsStr
 }
@@ -67,5 +66,5 @@ func commitID() string {
 }
 
 func main() {
-	fmt.Println(genLDFlags(time.Now().UTC().Format(time.RFC3339)))
+	fmt.Println(genLDFlags("2017-08-05T00-00-53Z"))
 }
