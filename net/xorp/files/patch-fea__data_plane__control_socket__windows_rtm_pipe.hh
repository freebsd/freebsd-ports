--- ./fea/data_plane/control_socket/windows_rtm_pipe.hh.orig	2011-03-16 21:16:01.000000000 +0000
+++ ./fea/data_plane/control_socket/windows_rtm_pipe.hh	2014-02-26 21:17:13.000000000 +0000
@@ -29,7 +29,7 @@
 #include "libxorp/exceptions.hh"
 
 class WinRtmPipeObserver;
-struct WinRtmPipePlumber;
+// struct WinRtmPipePlumber;
 
 /**
  * WinRtmPipe class opens a routing socket and forwards data arriving
