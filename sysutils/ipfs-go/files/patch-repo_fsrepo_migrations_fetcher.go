--- repo/fsrepo/migrations/fetcher.go.orig	2022-01-10 17:25:02 UTC
+++ repo/fsrepo/migrations/fetcher.go
@@ -10,7 +10,7 @@ import (
 
 const (
 	// Current distribution to fetch migrations from
-	CurrentIpfsDist = "/ipfs/QmP7tLxzhLU1KauTRX3jkVkF93pCv4skcceyUYMhf4AKJR" // fs-repo-migrations v2.0.2
+	CurrentIpfsDist = "" // fs-repo-migrations v2.0.2
 	// Latest distribution path.  Default for fetchers.
 	LatestIpfsDist = "/ipns/dist.ipfs.io"
 
