--- src/sessionmanagerplugin/session/portsession/muxportforwarding.go.orig	2026-10-09 23:34:02 UTC
+++ src/sessionmanagerplugin/session/portsession/muxportforwarding.go
@@ -87,7 +87,7 @@ func (p *MuxPortForwarding) Stop() {
 		p.muxClient.close()
 	}
 	p.cleanUp()
-	os.Exit(0)
+	osExit(0)
 }
 
 // InitializeStreams initializes i/o streams
