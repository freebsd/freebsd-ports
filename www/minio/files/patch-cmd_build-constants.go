--- cmd/build-constants.go.orig	2017-08-16 12:53:18.195373000 -0700
+++ cmd/build-constants.go	2017-08-16 12:54:24.704904000 -0700
@@ -23,14 +23,14 @@
 	GOPATH = ""
 
 	// Go get development tag.
-	goGetTag = "DEVELOPMENT.GOGET"
+	goGetTag = "RELEASE.2017-08-05T00-00-53Z"
 
 	// Version - version time.RFC3339.
-	Version = goGetTag
+	Version = "2017-08-05T00:00:53Z"
 	// ReleaseTag - release tag in TAG.%Y-%m-%dT%H-%M-%SZ.
-	ReleaseTag = goGetTag
+	ReleaseTag = "RELEASE.2017-08-05T00-00-53Z"
 	// CommitID - latest commit id.
-	CommitID = goGetTag
+	CommitID = "aeafe668d8b6d25caac671d59e2b0f0473ce35d0"
 	// ShortCommitID - first 12 characters from CommitID.
 	ShortCommitID = CommitID[:12]
 )
