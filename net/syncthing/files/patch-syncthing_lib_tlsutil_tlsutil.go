--- syncthing/lib/tlsutil/tlsutil.go.orig	2020-08-11 08:56:46 UTC
+++ syncthing/lib/tlsutil/tlsutil.go
@@ -106,6 +106,7 @@ func NewCertificate(certFile, keyFile, commonName stri
 		Subject: pkix.Name{
 			CommonName: commonName,
 		},
+		DNSNames:              []string{commonName},
 		NotBefore:             notBefore,
 		NotAfter:              notAfter,
 		SignatureAlgorithm:    x509.ECDSAWithSHA256,
