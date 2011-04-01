--- chrome/renderer/pepper_devices.cc.orig	2011-03-23 00:44:41.089126548 +0200
+++ chrome/renderer/pepper_devices.cc	2011-03-23 00:45:00.811641561 +0200
@@ -52,7 +52,7 @@
   uint32 buffer_size = width * height * kBytesPerPixel;
 
   // Allocate the transport DIB and the PlatformCanvas pointing to it.
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
   // On the Mac, shared memory has to be created in the browser in order to
   // work in the sandbox.  Do this by sending a message to the browser
   // requesting a TransportDIB (see also
