--- buildscripts/gen-ldflags.go.orig	2017-02-22 14:17:45.000000000 -0500
+++ buildscripts/gen-ldflags.go	2017-03-16 16:57:45.209088000 -0500
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
+	ldflagsStr = "-X github.com/minio/minio/cmd.Version=2017-03-16T21:50:32Z"
+	ldflagsStr += " -X github.com/minio/minio/cmd.ReleaseTag=RELEASE.2017-03-16T21-50-32Z"
+        ldflagsStr += " -X github.com/minio/minio/cmd.CommitID=78dbb5bf141b4ff8003b7e5ef9b665a147c465bc"
+	ldflagsStr += " -X github.com/minio/minio/cmd.ShortCommitID=78dbb5bf141b4"
 	ldflagsStr += " -X github.com/minio/minio/cmd.GOPATH=" + os.Getenv("GOPATH")
 	return ldflagsStr
 }
@@ -67,5 +66,5 @@ func commitID() string {
 }
 
 func main() {
-	fmt.Println(genLDFlags(time.Now().UTC().Format(time.RFC3339)))
+	fmt.Println(genLDFlags("2017-03-16T21-50-32Z"))
 }
