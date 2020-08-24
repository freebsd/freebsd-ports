--- syncthing/lib/connections/service.go.orig	2020-08-11 08:56:46 UTC
+++ syncthing/lib/connections/service.go
@@ -305,7 +305,11 @@ func (s *service) handle(ctx context.Context) {
 		if certName == "" {
 			certName = s.tlsDefaultCommonName
 		}
-		if err := remoteCert.VerifyHostname(certName); err != nil {
+		if remoteCert.Subject.CommonName == certName {
+			// All good. We do this check because our old style certificates
+			// have "syncthing" in the CommonName field and no SANs, which
+			// is not accepted by VerifyHostname() any more as of Go 1.15.
+		} else if err := remoteCert.VerifyHostname(certName); err != nil {
 			// Incorrect certificate name is something the user most
 			// likely wants to know about, since it's an advanced
 			// config. Warn instead of Info.
