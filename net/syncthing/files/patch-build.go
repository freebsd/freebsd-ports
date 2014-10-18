--- build.go.orig	2014-10-10 03:17:54.000000000 +0000
+++ build.go	2014-10-10 03:21:21.000000000 +0000
@@ -299,18 +299,11 @@
 }
 
 func version() string {
-	v := run("git", "describe", "--always", "--dirty")
-	v = versionRe.ReplaceAllFunc(v, func(s []byte) []byte {
-		s[0] = '+'
-		return s
-	})
-	return string(v)
+	return string("v0.10.1")
 }
 
 func buildStamp() int64 {
-	bs := run("git", "show", "-s", "--format=%ct")
-	s, _ := strconv.ParseInt(string(bs), 10, 64)
-	return s
+	return 1413115780
 }
 
 func buildUser() string {
