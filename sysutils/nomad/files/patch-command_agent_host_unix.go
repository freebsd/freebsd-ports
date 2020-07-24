--- command/agent/host/unix.go.orig	2020-07-08 22:29:33 UTC
+++ command/agent/host/unix.go
@@ -64,5 +64,5 @@ func (d *df) total() uint64 {
 }
 
 func (d *df) available() uint64 {
-	return d.s.Bavail * uint64(d.s.Bsize)
+	return uint64(d.s.Bavail) * uint64(d.s.Bsize)
 }
