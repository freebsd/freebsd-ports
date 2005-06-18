--- wrapper/asteriskaudio.cxx.orig	Fri Jun 17 13:32:45 2005
+++ wrapper/asteriskaudio.cxx	Fri Jun 17 13:33:19 2005
@@ -164,7 +164,7 @@ PAsteriskSoundChannel::~PAsteriskSoundCh
 	WRAPTRACE(3, "Total I/Os: read=" << readCount << ", write=" << writeCount);
 	WRAPTRACE(3, "Short I/Os: write=" << shortWriteCount);
 	WRAPTRACE(4, "Object deleted.");
-	baseChannel = NULL;
+//	baseChannel = NULL;
 }
 
 PStringArray PAsteriskSoundChannel::GetDeviceNames(Directions dir)
@@ -231,7 +231,7 @@ BOOL PAsteriskSoundChannel::Open(const P
 	**********/
 	if (deviceFd < 0)
 		return FALSE;
-	baseChannel = this;  // XXX Use the old interface of the PSoundChannel
+//	baseChannel = this;  // XXX Use the old interface of the PSoundChannel
 	os_handle = deviceFd;
 	mediaFormat = mediaFmt;
 	frameTime = frameTm;
