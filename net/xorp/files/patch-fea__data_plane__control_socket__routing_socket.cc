--- fea/data_plane/control_socket/routing_socket.cc.orig	2012-01-11 17:56:10 UTC
+++ fea/data_plane/control_socket/routing_socket.cc
@@ -240,9 +240,10 @@ RoutingSocket::io_event(XorpFd fd, IoEve
 // Observe routing sockets activity
 //
 
-struct RoutingSocketPlumber {
+class RoutingSocketPlumber {
     typedef RoutingSocket::ObserverList ObserverList;
 
+public:
     static void
     plumb(RoutingSocket& r, RoutingSocketObserver* o)
     {
