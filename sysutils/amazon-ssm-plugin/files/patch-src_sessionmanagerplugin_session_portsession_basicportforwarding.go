--- src/sessionmanagerplugin/session/portsession/basicportforwarding.go.orig	2026-10-09 23:34:02 UTC
+++ src/sessionmanagerplugin/session/portsession/basicportforwarding.go
@@ -51,6 +51,8 @@ var acceptConnection = func(log log.T, listener net.Li
 	return listener.Accept()
 }
 
+var osExit = os.Exit
+
 // IsStreamNotSet checks if stream is not set
 func (p *BasicPortForwarding) IsStreamNotSet() (status bool) {
 	return p.stream == nil
@@ -61,7 +63,7 @@ func (p *BasicPortForwarding) Stop() {
 	if p.stream != nil {
 		(*p.stream).Close()
 	}
-	os.Exit(0)
+	osExit(0)
 }
 
 // InitializeStreams establishes connection and initializes the stream
