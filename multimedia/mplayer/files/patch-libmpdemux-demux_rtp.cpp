--- libmpdemux/demux_rtp.cpp.orig	Thu Jun  3 15:30:55 2004
+++ libmpdemux/demux_rtp.cpp	Thu Jul 22 23:29:36 2004
@@ -407,7 +407,7 @@
   delete rtpState->sdpDescription;
   delete rtpState;
 
-  delete env; delete scheduler;
+  env->reclaim(); delete scheduler;
 }
 
 ////////// Extra routines that help implement the above interface functions:
