--- plugins/meta/dnsname/files.go.orig	2025-12-28 12:10:39 UTC
+++ plugins/meta/dnsname/files.go
@@ -54,18 +54,14 @@ func checkForDNSMasqConfFile(conf dnsNameFile) error {
 	if err != nil {
 		return err
 	}
+	// FreeBSD uses pf, not iptables - skip firewall rule setup
+	// The host's pf should already allow local DNS traffic
 	ip, err := iptables.New()
-	if err != nil {
-		return err
-	}
-	args := []string{"-i", conf.NetworkInterface, "-p", "udp", "-m", "udp", "--dport", "53", "-j", "ACCEPT"}
-	exists, err := ip.Exists("filter", "INPUT", args...)
-	if err != nil {
-		return err
-	}
-	if !exists {
-		if err := ip.Insert("filter", "INPUT", 1, args...); err != nil {
-			return err
+	if err == nil {
+		args := []string{"-i", conf.NetworkInterface, "-p", "udp", "-m", "udp", "--dport", "53", "-j", "ACCEPT"}
+		exists, _ := ip.Exists("filter", "INPUT", args...)
+		if !exists {
+			_ = ip.Insert("filter", "INPUT", 1, args...)
 		}
 	}
 	// Generate the template and compile it.
