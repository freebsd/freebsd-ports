--- buildscripts/gen-ldflags.go.orig	2017-02-15 20:51:19.000000000 -0500
+++ buildscripts/gen-ldflags.go	2017-02-22 14:17:45.209088000 -0500
@@ -23,15 +23,14 @@ import (
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
+	ldflagsStr = "-X github.com/minio/minio/cmd.Version=2017-02-16T01:47:30Z"
+	ldflagsStr += " -X github.com/minio/minio/cmd.ReleaseTag=RELEASE.2017-02-16T01-47-30Z"
+        ldflagsStr += " -X github.com/minio/minio/cmd.CommitID=3d98311d9f4ceb78dba996dcdc0751253241e697"
+	ldflagsStr += " -X github.com/minio/minio/cmd.ShortCommitID=83abb310b4ce"
 	ldflagsStr += " -X github.com/minio/minio/cmd.GOPATH=" + os.Getenv("GOPATH")
 	return ldflagsStr
 }
@@ -67,5 +66,5 @@ func commitID() string {
 }
 
 func main() {
-	fmt.Println(genLDFlags(time.Now().UTC().Format(time.RFC3339)))
+	fmt.Println(genLDFlags("2017-02-16T01-47-30Z"))
 }
