--- cmd/build-constants.go.orig	2017-08-16 13:32:17.231512000 -0700
+++ cmd/build-constants.go	2017-08-16 13:33:11.450401000 -0700
@@ -18,11 +18,11 @@
 
 var (
 	// Version - version time.RFC3339.
-	Version = "DEVELOPMENT.GOGET"
+	Version = "2017-06-15T03:38:43Z"
 	// ReleaseTag - release tag in TAG.%Y-%m-%dT%H-%M-%SZ.
-	ReleaseTag = "DEVELOPMENT.GOGET"
+	ReleaseTag = "RELEASE.2017-06-15T03-38-43Z"
 	// CommitID - latest commit id.
-	CommitID = "DEVELOPMENT.GOGET"
+	CommitID = "631f7fc194fe0ad8d26cb16ca264ca6665fcd151"
 	// ShortCommitID - first 12 characters from CommitID.
 	ShortCommitID = CommitID[:12]
 )
