--- syncthing/lib/beacon/multicast.go.orig	2021-07-06 12:51:32 UTC
+++ syncthing/lib/beacon/multicast.go
@@ -126,6 +126,9 @@ func readMulticasts(ctx context.Context, outbox chan<-
 	pconn := ipv6.NewPacketConn(conn)
 	joined := 0
 	for _, intf := range intfs {
+		if intf.Flags&net.FlagUp == 0 || intf.Flags&net.FlagMulticast == 0 || intf.Name == "ipfw0" {
+			continue
+		}
 		err := pconn.JoinGroup(&intf, &net.UDPAddr{IP: gaddr.IP})
 		if err != nil {
 			l.Debugln("IPv6 join", intf.Name, "failed:", err)
