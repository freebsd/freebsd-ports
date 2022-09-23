--- caddy.go.orig	2022-09-22 16:12:41 UTC
+++ caddy.go
@@ -824,6 +824,10 @@ func InstanceID() (uuid.UUID, error) {
 	return uuid.ParseBytes(uuidFileBytes)
 }
 
+// VersionString uses a predefined version string to short-circuit
+// the Version() function below, to simplify vendor packaging.
+var VersionString string
+
 // Version returns the Caddy version in a simple/short form, and
 // a full version string. The short form will not have spaces and
 // is intended for User-Agent strings and similar, but may be
@@ -841,6 +845,11 @@ func InstanceID() (uuid.UUID, error) {
 //
 // This function is experimental and subject to change or removal.
 func Version() (simple, full string) {
+	// Use VersionString if provided (eg. through -ldflags -X)
+	if VersionString != "" {
+		return VersionString, VersionString
+	}
+
 	// the currently-recommended way to build Caddy involves
 	// building it as a dependency so we can extract version
 	// information from go.mod tooling; once the upstream
