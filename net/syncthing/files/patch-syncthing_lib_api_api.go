--- syncthing/lib/api/api.go.orig	2020-08-11 08:56:46 UTC
+++ syncthing/lib/api/api.go
@@ -149,7 +149,7 @@ func (s *service) getListener(guiCfg config.GUIConfigu
 	// If the certificate has expired or will expire in the next month, fail
 	// it and generate a new one.
 	if err == nil {
-		err = checkExpiry(cert)
+		err = shouldRegenerateCertificate(cert)
 	}
 	if err != nil {
 		l.Infoln("Loading HTTPS certificate:", err)
@@ -1736,7 +1736,11 @@ func addressIsLocalhost(addr string) bool {
 	}
 }
 
-func checkExpiry(cert tls.Certificate) error {
+// shouldRegenerateCertificate checks for certificate expiry or other known
+// issues with our API/GUI certificate and returns either nil (leave the
+// certificate alone) or an error describing the reason the certificate
+// should be regenerated.
+func shouldRegenerateCertificate(cert tls.Certificate) error {
 	leaf := cert.Leaf
 	if leaf == nil {
 		// Leaf can be nil or not, depending on how parsed the certificate
@@ -1752,10 +1756,19 @@ func checkExpiry(cert tls.Certificate) error {
 		}
 	}
 
-	if leaf.Subject.String() != leaf.Issuer.String() ||
-		len(leaf.DNSNames) != 0 || len(leaf.IPAddresses) != 0 {
-		// The certificate is not self signed, or has DNS/IP attributes we don't
+	if leaf.Subject.String() != leaf.Issuer.String() || len(leaf.IPAddresses) != 0 {
+		// The certificate is not self signed, or has IP attributes we don't
 		// add, so we leave it alone.
+		return nil
+	}
+	if len(leaf.DNSNames) > 1 {
+		// The certificate has more DNS SANs attributes than we ever add, so
+		// we leave it alone.
+		return nil
+	}
+	if len(leaf.DNSNames) == 1 && leaf.DNSNames[0] != leaf.Issuer.CommonName {
+		// The one SAN is different from the issuer, so it's not one of our
+		// newer self signed certificates.
 		return nil
 	}
 
