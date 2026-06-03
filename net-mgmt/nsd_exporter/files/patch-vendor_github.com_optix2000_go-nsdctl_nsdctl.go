--- vendor/github.com/optix2000/go-nsdctl/nsdctl.go.orig	2026-04-04 07:20:36 UTC
+++ vendor/github.com/optix2000/go-nsdctl/nsdctl.go
@@ -116,7 +116,7 @@ type NSDClient struct {
 }
 
 // NewClientFromConfig tries to autodetect and create a new NSDClient from an config file
-func NewClientFromConfig(configPath string) (*NSDClient, error) {
+func NewClientFromConfig(configPath string, skipTLSverify bool) (*NSDClient, error) {
 	filename := path.Base(configPath)
 
 	var detectedType string
@@ -189,10 +189,10 @@ func NewClientFromConfig(configPath string) (*NSDClien
 	}
 
 	if port != 0 {
-		hostString = "127.0.0.1:" + string(port)
+		hostString = "127.0.0.1:" + strconv.FormatUint(uint64(port), 10)
 	}
 
-	return NewClient(detectedType, hostString, caFile, keyFile, certFile, false)
+	return NewClient(detectedType, hostString, caFile, keyFile, certFile, skipTLSverify)
 }
 
 // NewClient creates a complete new NSDClient and returns any errors encountered
