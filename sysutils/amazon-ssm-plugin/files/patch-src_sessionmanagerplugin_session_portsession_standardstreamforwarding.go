--- src/sessionmanagerplugin/session/portsession/standardstreamforwarding.go.orig	2026-10-09 23:34:02 UTC
+++ src/sessionmanagerplugin/session/portsession/standardstreamforwarding.go
@@ -42,7 +42,7 @@ func (p *StandardStreamForwarding) Stop() {
 func (p *StandardStreamForwarding) Stop() {
 	p.inputStream.Close()
 	p.outputStream.Close()
-	os.Exit(0)
+	osExit(0)
 }
 
 // InitializeStreams initializes the streams with its file descriptors
