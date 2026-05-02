--- internal/gitaly/blob.go.orig	2026-05-02 00:22:07 UTC
+++ internal/gitaly/blob.go
@@ -70,7 +70,7 @@ func (client *BlobClient) SendListBlobs(ctx context.Co
 			return fmt.Errorf("marshal list blobs response: %v", err)
 		}
 
-		if len(frame) > math.MaxUint32 {
+		if int64(len(frame)) > math.MaxUint32 {
 			return fmt.Errorf("frame too large: %d bytes", len(frame))
 		}
 
