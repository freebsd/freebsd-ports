--- pkg/config/log.go.orig	2020-11-26 10:38:37 UTC
+++ pkg/config/log.go
@@ -16,6 +16,7 @@ import (
 	"strconv"
 	"strings"
 	"time"
+	"regexp"
 
 	seelogCfg "github.com/DataDog/datadog-agent/pkg/config/seelog"
 	"github.com/DataDog/datadog-agent/pkg/util/log"
@@ -324,8 +325,9 @@ func parseShortFilePath(params string) seelog.Formatte
 
 func extractShortPathFromFullPath(fullPath string) string {
 	// We want to trim the part containing the path of the project
-	// ie DataDog/datadog-agent/ or DataDog/datadog-process-agent/
-	slices := strings.Split(fullPath, "-agent/")
+	// ie DataDog/datadog-agent-x.y-z/ or DataDog/datadog-process-agent-x.y.z/
+	regex := regexp.MustCompile("-agent-[0-9.]*/")
+    	slices := regex.Split(fullPath, -1)
 	return slices[len(slices)-1]
 }
 
