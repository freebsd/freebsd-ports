--- src/sessionmanagerplugin/session/portsession/basicportforwarding_test.go.orig	2026-10-09 23:34:02 UTC
+++ src/sessionmanagerplugin/session/portsession/basicportforwarding_test.go
@@ -28,6 +28,10 @@ import (
 	"github.com/stretchr/testify/mock"
 )
 
+func init() {
+	osExit = func(code int) {}
+}
+
 // This test passes ctrl+c signal which blocks running of all other tests.
 func TestSetSessionHandlers(t *testing.T) {
 	mockLog.Infof("TestStartSession!!!!!")
