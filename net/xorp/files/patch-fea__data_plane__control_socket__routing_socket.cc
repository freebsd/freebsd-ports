--- ./fea/data_plane/control_socket/routing_socket.cc.orig	2011-03-16 21:27:46.000000000 +0000
+++ ./fea/data_plane/control_socket/routing_socket.cc	2014-02-26 21:17:13.000000000 +0000
@@ -240,9 +240,10 @@
 // Observe routing sockets activity
 //
 
-struct RoutingSocketPlumber {
+class RoutingSocketPlumber {
     typedef RoutingSocket::ObserverList ObserverList;
 
+public:
     static void
     plumb(RoutingSocket& r, RoutingSocketObserver* o)
     {
