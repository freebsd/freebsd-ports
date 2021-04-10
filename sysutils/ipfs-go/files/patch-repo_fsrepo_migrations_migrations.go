--- repo/fsrepo/migrations/migrations.go.orig	2021-03-02 03:58:49 UTC
+++ repo/fsrepo/migrations/migrations.go
@@ -15,7 +15,7 @@ import (
 	"strings"
 )
 
-var DistPath = "https://ipfs.io/ipfs/QmYRLRDKobvg1AXTGeK5Xk6ntWTsjGiHbyNKhWfz7koGpa"
+var DistPath = ""
 
 func init() {
 	if dist := os.Getenv("IPFS_DIST_PATH"); dist != "" {
