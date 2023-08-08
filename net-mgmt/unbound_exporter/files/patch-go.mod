--- go.mod.orig	2023-03-23 10:12:21 UTC
+++ go.mod
@@ -1,15 +1,23 @@
 module github.com/letsencrypt/unbound_exporter
 
-go 1.16
+go 1.17
 
 require (
-	github.com/cespare/xxhash/v2 v2.1.2 // indirect
 	github.com/go-kit/log v0.2.0
-	github.com/golang/protobuf v1.5.2 // indirect
-	github.com/google/go-cmp v0.5.6 // indirect
 	github.com/prometheus/client_golang v1.11.0
 	github.com/prometheus/common v0.32.1
+)
+
+require (
+	github.com/beorn7/perks v1.0.1 // indirect
+	github.com/cespare/xxhash/v2 v2.1.2 // indirect
+	github.com/go-logfmt/logfmt v0.5.1 // indirect
+	github.com/golang/protobuf v1.5.2 // indirect
+	github.com/google/go-cmp v0.5.6 // indirect
+	github.com/matttproud/golang_protobuf_extensions v1.0.1 // indirect
+	github.com/pkg/errors v0.9.1 // indirect
+	github.com/prometheus/client_model v0.2.0 // indirect
 	github.com/prometheus/procfs v0.7.3 // indirect
-	golang.org/x/sys v0.0.0-20211112193437-faf0a1b62c6b // indirect
+	golang.org/x/sys v0.6.0 // indirect
 	google.golang.org/protobuf v1.27.1 // indirect
 )
