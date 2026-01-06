--- syncthing/lib/beacon/multicast.go.orig	2026-01-06 13:20:06 UTC
+++ syncthing/lib/beacon/multicast.go
@@ -129,7 +129,7 @@ func readMulticasts(ctx context.Context, outbox chan<-
 	pconn := ipv6.NewPacketConn(conn)
 	joined := 0
 	for _, intf := range intfs {
-		if intf.Flags&net.FlagMulticast == 0 {
+		if intf.Flags&net.FlagUp == 0 || intf.Flags&net.FlagMulticast == 0 || intf.Name == "ipfw0" {
 			slog.DebugContext(ctx, "Not joining multicast group on non-multicast interface", "name", intf.Name, slog.String("flags", intf.Flags.String()))
 			continue
 		}
