--- xbmc/cores/dvdplayer/DVDCodecs/Video/VDPAU.cpp.orig	2011-03-05 04:33:37.000000000 +0100
+++ xbmc/cores/dvdplayer/DVDCodecs/Video/VDPAU.cpp	2011-04-25 19:11:54.000000000 +0200
@@ -647,8 +647,9 @@
 
 void CVDPAU::InitVDPAUProcs()
 {
-  char* error;
+  const char* error;
 
+  (void)dlerror();
   dl_vdp_device_create_x11 = (VdpStatus (*)(Display*, int, VdpDevice*, VdpStatus (**)(VdpDevice, VdpFuncId, void**)))dlsym(dl_handle, (const char*)"vdp_device_create_x11");
   error = dlerror();
   if (error)
