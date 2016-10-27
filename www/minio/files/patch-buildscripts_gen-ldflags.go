--- buildscripts/gen-ldflags.go.orig	2016-10-24 20:34:01 UTC
+++ buildscripts/gen-ldflags.go
@@ -23,15 +23,13 @@ import (
 	"os"
 	"os/exec"
 	"strings"
-	"time"
 )
 
 func genLDFlags(version string) string {
 	var ldflagsStr string
-	ldflagsStr = "-X github.com/minio/minio/cmd.Version=" + version
-	ldflagsStr += " -X github.com/minio/minio/cmd.ReleaseTag=" + releaseTag(version)
-	ldflagsStr += " -X github.com/minio/minio/cmd.CommitID=" + commitID()
-	ldflagsStr += " -X github.com/minio/minio/cmd.ShortCommitID=" + commitID()[:12]
+	ldflagsStr = "-X github.com/minio/minio/cmd.Version=2016-10-24T21:23:47Z"
+	ldflagsStr += " -X github.com/minio/minio/cmd.ReleaseTag=RELEASE.2016-10-24T21-23-47Z"
+        ldflagsStr += " -X github.com/minio/minio/cmd.CommitID=048af5e5cdc1344e83231c09079828a3d289e6df"
 	ldflagsStr += " -X github.com/minio/minio/cmd.GOPATH=" + os.Getenv("GOPATH")
 	return ldflagsStr
 }
@@ -67,5 +65,5 @@ func commitID() string {
 }
 
 func main() {
-	fmt.Println(genLDFlags(time.Now().UTC().Format(time.RFC3339)))
+	fmt.Println(genLDFlags("2016-10-24T21:23:47Z"))
 }
