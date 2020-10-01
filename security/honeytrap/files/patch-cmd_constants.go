--- cmd/constants.go.orig	2020-08-11 10:18:40 UTC
+++ cmd/constants.go
@@ -19,15 +19,12 @@ var (
 	// GOPATH - GOPATH value at the time of build.
 	GOPATH = ""
 
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
