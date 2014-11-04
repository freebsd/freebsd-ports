--- build.go.orig	2014-10-24 08:27:14.000000000 +0000
+++ build.go	2014-10-25 12:42:18.706050568 +0000
@@ -35,7 +35,6 @@
 	"runtime"
 	"strconv"
 	"strings"
-	"time"
 )
 
 var (
@@ -302,24 +301,11 @@
 }
 
 func getVersion() string {
-	v, err := runError("git", "describe", "--always", "--dirty")
-	if err != nil {
-		return "unknown-dev"
-	}
-	v = versionRe.ReplaceAllFunc(v, func(s []byte) []byte {
-		s[0] = '+'
-		return s
-	})
-	return string(v)
+	return string("v0.10.4")
 }
 
 func buildStamp() int64 {
-	bs, err := runError("git", "show", "-s", "--format=%ct")
-	if err != nil {
-		return time.Now().Unix()
-	}
-	s, _ := strconv.ParseInt(string(bs), 10, 64)
-	return s
+	return 1414418716
 }
 
 func buildUser() string {
