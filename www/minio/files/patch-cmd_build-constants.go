--- cmd/build-constants.go.orig	2017-09-29 19:08:23 UTC
+++ cmd/build-constants.go
@@ -23,14 +23,14 @@ var (
 	GOPATH = ""
 
 	// Go get development tag.
-	goGetTag = "DEVELOPMENT.GOGET"
+	goGetTag = "RELEASE.2017-09-29T19-16-56Z"
 
 	// Version - version time.RFC3339.
-	Version = goGetTag
+	Version = "2017-09-29T19:16:56Z"
 	// ReleaseTag - release tag in TAG.%Y-%m-%dT%H-%M-%SZ.
-	ReleaseTag = goGetTag
+	ReleaseTag = "RELEASE.2017-09-29T19-16-56Z"
 	// CommitID - latest commit id.
-	CommitID = goGetTag
+	CommitID = "aeafe668d8b6d25caac671d59e2b0f0473ce35d0"
 	// ShortCommitID - first 12 characters from CommitID.
 	ShortCommitID = CommitID[:12]
 )
