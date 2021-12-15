--- command/agent/host/unix.go.orig	2021-11-24 18:54:06 UTC
+++ command/agent/host/unix.go
@@ -65,5 +65,5 @@ func (d *df) total() uint64 {
 }
 
 func (d *df) available() uint64 {
-	return d.s.Bavail * uint64(d.s.Bsize)
+	return uint64(d.s.Bavail) * uint64(d.s.Bsize)
 }
