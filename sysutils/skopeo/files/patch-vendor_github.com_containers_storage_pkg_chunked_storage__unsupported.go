--- vendor/github.com/containers/storage/pkg/chunked/storage_unsupported.go.orig	2025-02-04 11:32:21 UTC
+++ vendor/github.com/containers/storage/pkg/chunked/storage_unsupported.go
@@ -13,5 +13,5 @@ func GetDiffer(ctx context.Context, store storage.Stor
 
 // GetDiffer returns a differ than can be used with ApplyDiffWithDiffer.
 func GetDiffer(ctx context.Context, store storage.Store, blobDigest digest.Digest, blobSize int64, annotations map[string]string, iss ImageSourceSeekable) (graphdriver.Differ, error) {
-	return nil, errors.New("format not supported on this system")
+	return nil, newErrFallbackToOrdinaryLayerDownload(errors.New("format not supported on this system"))
 }
