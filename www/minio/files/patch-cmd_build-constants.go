--- cmd/build-constants.go.orig	2020-02-26 23:29:50 UTC
+++ cmd/build-constants.go
@@ -25,15 +25,12 @@ var (
 	// GOROOT - GOROOT value at the time of build.
 	GOROOT = ""
 
-	// Go get development tag.
-	goGetTag = "DEVELOPMENT.GOGET"
-
 	// Version - version time.RFC3339.
-	Version = goGetTag
+	Version = ""
 	// ReleaseTag - release tag in TAG.%Y-%m-%dT%H-%M-%SZ.
-	ReleaseTag = goGetTag
+	ReleaseTag = ""
 	// CommitID - latest commit id.
-	CommitID = goGetTag
+	CommitID = ""
 	// ShortCommitID - first 12 characters from CommitID.
 	ShortCommitID = CommitID[:12]
 )
