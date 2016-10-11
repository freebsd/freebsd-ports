--- agent/platform/platform_unix.go.orig	2016-07-06 21:51:35 UTC
+++ agent/platform/platform_unix.go
@@ -20,6 +20,7 @@ import (
 	"os"
 	"os/exec"
 	"path/filepath"
+	"runtime"
 	"strings"
 
 	"github.com/aws/amazon-ssm-agent/agent/fileutil"
@@ -29,6 +30,7 @@ import (
 const (
 	systemReleaseCommand   = "/etc/system-release"
 	redhatReleaseCommand   = "/etc/redhat-release"
+	unameCommand           = "/usr/bin/uname"
 	lsbReleaseCommand      = "lsb_release"
 	fetchingDetailsMessage = "fetching platform details from %v"
 	errorOccurredMessage   = "There was an error running %v, err: %v"
@@ -94,6 +96,18 @@ func getPlatformDetails(log log.T) (name
 			versionData := strings.Split(data[1], "(")
 			version = strings.TrimSpace(versionData[0])
 		}
+	} else if runtime.GOOS == "freebsd" {
+		log.Debugf(fetchingDetailsMessage, unameCommand)
+
+		if contentsBytes, err = exec.Command(unameCommand, "-sr").Output(); err != nil {
+			log.Debugf(fetchingDetailsMessage, lsbReleaseCommand, err)
+			return
+		}
+		log.Debugf(commandOutputMessage, contentsBytes)
+
+		data := strings.Split(string(contentsBytes), " ")
+		name = strings.TrimSpace(data[0])
+		version = strings.TrimSpace(data[1])
 	} else {
 		log.Debugf(fetchingDetailsMessage, lsbReleaseCommand)
 
