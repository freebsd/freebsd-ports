--- go.mod.orig	2026-07-15 20:28:55.935967000 +0000
+++ go.mod	2026-07-15 20:21:51.176795000 +0000
@@ -1,6 +1,6 @@
 module github.com/GoogleCloudPlatform/guest-agent
 
-go 1.26
+go 1.25.8
 
 replace github.com/GoogleCloudPlatform/guest-agent/metadata => ../metadata
 
@@ -50,8 +50,8 @@
 	github.com/go-logr/stdr v1.2.2 // indirect
 	github.com/google/go-configfs-tsm v0.3.3 // indirect
 	github.com/google/go-eventlog v0.0.3-0.20260617163629-883cc5652c69 // indirect
-	github.com/google/go-sev-guest v0.15.0 // indirect
-	github.com/google/go-tdx-guest v0.3.2-0.20250814004405-ffb0869e6f4d // indirect
+	github.com/google/go-sev-guest v0.15.1-0.20260714230530-c930ed67bebf // indirect
+	github.com/google/go-tdx-guest v0.3.2-0.20260714160433-fff6cc779034 // indirect
 	github.com/google/logger v1.1.2 // indirect
 	github.com/google/s2a-go v0.1.9 // indirect
 	github.com/google/uuid v1.6.0 // indirect
@@ -77,4 +77,4 @@
 	google.golang.org/genproto v0.0.0-20260630182238-925bb5da69e7 // indirect
 	google.golang.org/genproto/googleapis/api v0.0.0-20260630182238-925bb5da69e7 // indirect
 	google.golang.org/genproto/googleapis/rpc v0.0.0-20260630182238-925bb5da69e7 // indirect
-)
\ No newline at end of file
+)
