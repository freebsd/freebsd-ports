--- vendor/github.com/containers/common/pkg/config/config.go.orig	2023-07-21 12:24:32 UTC
+++ vendor/github.com/containers/common/pkg/config/config.go
@@ -51,7 +51,7 @@ const (
 	BoltDBStateStore RuntimeStateStore = iota
 )
 
-var validImageVolumeModes = []string{"bind", "tmpfs", "ignore"}
+var validImageVolumeModes = []string{"nullfs", "tmpfs", "ignore"}
 
 // ProxyEnv is a list of Proxy Environment variables
 var ProxyEnv = []string{
