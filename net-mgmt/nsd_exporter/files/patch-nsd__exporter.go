--- nsd_exporter.go.orig	2026-04-04 07:23:54 UTC
+++ nsd_exporter.go
@@ -26,6 +26,7 @@ var cert = flag.String("cert", "", "Client cert file l
 var key = flag.String("key", "", "Client key file location. Mutually exclusive with -config-file.")
 var ca = flag.String("ca", "", "Server CA file location. Mutually exclusive with -config-file.")
 var nsdAddr = flag.String("nsd-address", "", "NSD or Unbound control socket address.")
+var skipTLSverify = flag.Bool("skipTLSverify", false, "Skip TLS Verification")
 
 // Prom stuff
 var nsdToProm = strings.NewReplacer(".", "_")
@@ -199,8 +200,8 @@ func NewNSDCollector(nsdType string, hostString string
 	return collector, err
 }
 
-func NewNSDCollectorFromConfig(path string) (*NSDCollector, error) {
-	client, err := nsdctl.NewClientFromConfig(path)
+func NewNSDCollectorFromConfig(path string, skipVerify bool) (*NSDCollector, error) {
+	client, err := nsdctl.NewClientFromConfig(path, skipVerify)
 	if err != nil {
 		return nil, err
 	}
@@ -233,7 +234,7 @@ func main() {
 	if *cert != "" || *key != "" || *ca != "" || *nsdAddr != "" {
 		if *cert != "" && *key != "" && *ca != "" && *nsdAddr != "" {
 			// Build from arguments
-			nsdCollector, err = NewNSDCollector(*nsdType, *nsdAddr, *ca, *key, *cert, false)
+			nsdCollector, err = NewNSDCollector(*nsdType, *nsdAddr, *ca, *key, *cert, *skipTLSverify)
 			if err != nil {
 				log.Fatal(err)
 			}
@@ -242,7 +243,7 @@ func main() {
 		}
 	} else {
 		// Build from config
-		nsdCollector, err = NewNSDCollectorFromConfig(*nsdConfig)
+		nsdCollector, err = NewNSDCollectorFromConfig(*nsdConfig, *skipTLSverify)
 		if err != nil {
 			log.Fatal(err)
 		}
