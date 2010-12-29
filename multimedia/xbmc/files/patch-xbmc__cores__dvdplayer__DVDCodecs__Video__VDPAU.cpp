--- xbmc/cores/dvdplayer/DVDCodecs/Video/VDPAU.cpp.orig	2010-12-17 07:17:41.000000000 +0100
+++ xbmc/cores/dvdplayer/DVDCodecs/Video/VDPAU.cpp	2010-12-28 13:26:49.000000000 +0100
@@ -647,7 +647,7 @@
 
 void CVDPAU::InitVDPAUProcs()
 {
-  char* error;
+  const char* error;
 
   dl_vdp_device_create_x11 = (VdpStatus (*)(Display*, int, VdpDevice*, VdpStatus (**)(VdpDevice, VdpFuncId, void**)))dlsym(dl_handle, (const char*)"vdp_device_create_x11");
   error = dlerror();
