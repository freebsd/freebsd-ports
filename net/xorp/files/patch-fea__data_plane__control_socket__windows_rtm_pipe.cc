--- fea/data_plane/control_socket/windows_rtm_pipe.cc.orig	2012-01-11 17:56:10 UTC
+++ fea/data_plane/control_socket/windows_rtm_pipe.cc
@@ -288,9 +288,10 @@ WinRtmPipe::io_event(XorpFd fd, IoEventT
 // Observe routing sockets activity
 //
 
-struct WinRtmPipePlumber {
+class WinRtmPipePlumber {
     typedef WinRtmPipe::ObserverList ObserverList;
 
+public:
     static void
     plumb(WinRtmPipe& r, WinRtmPipeObserver* o)
     {
