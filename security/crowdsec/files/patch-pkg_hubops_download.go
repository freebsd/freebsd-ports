--- pkg/hubops/download.go.orig	2025-02-10 13:37:39 UTC
+++ pkg/hubops/download.go
@@ -114,6 +114,10 @@ func downloadDataSet(ctx context.Context, dataFolder s
 		}
 
 		for _, dataS := range data.Data {
+			if dataS.SourceURL == "" {
+				continue
+			}
+
 			// XXX: check context cancellation
 			destPath, err := cwhub.SafePath(dataFolder, dataS.DestPath)
 			if err != nil {
