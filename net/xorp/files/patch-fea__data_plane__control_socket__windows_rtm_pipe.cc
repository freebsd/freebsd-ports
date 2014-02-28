--- ./fea/data_plane/control_socket/windows_rtm_pipe.cc.orig	2011-03-16 21:16:01.000000000 +0000
+++ ./fea/data_plane/control_socket/windows_rtm_pipe.cc	2014-02-26 21:17:13.000000000 +0000
@@ -288,9 +288,10 @@
 // Observe routing sockets activity
 //
 
-struct WinRtmPipePlumber {
+class WinRtmPipePlumber {
     typedef WinRtmPipe::ObserverList ObserverList;
 
+public:
     static void
     plumb(WinRtmPipe& r, WinRtmPipeObserver* o)
     {
