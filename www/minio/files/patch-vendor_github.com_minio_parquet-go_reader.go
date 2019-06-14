--- vendor/github.com/minio/parquet-go/reader.go.orig	2019-06-14 19:46:33 UTC
+++ vendor/github.com/minio/parquet-go/reader.go
@@ -22,7 +22,7 @@ import (
 	"io"
 
 	"git.apache.org/thrift.git/lib/go/thrift"
-	"github.com/minio/minio-go/pkg/set"
+	"github.com/swills/minio-go/pkg/set"
 	"github.com/minio/parquet-go/gen-go/parquet"
 )
 
