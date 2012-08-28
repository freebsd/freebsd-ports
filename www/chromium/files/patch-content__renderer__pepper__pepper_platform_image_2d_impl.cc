--- content/renderer/pepper/pepper_platform_image_2d_impl.cc.orig	2012-07-18 10:01:27.000000000 +0300
+++ content/renderer/pepper/pepper_platform_image_2d_impl.cc	2012-07-25 21:15:02.000000000 +0300
@@ -31,7 +31,7 @@
   UMA_HISTOGRAM_COUNTS("Plugin.PepperImage2DSize", buffer_size);
 
   // Allocate the transport DIB and the PlatformCanvas pointing to it.
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
   // On the Mac, shared memory has to be created in the browser in order to
   // work in the sandbox.  Do this by sending a message to the browser
   // requesting a TransportDIB (see also
@@ -66,7 +66,7 @@
   *byte_count = dib_->size();
 #if defined(OS_WIN)
   return reinterpret_cast<intptr_t>(dib_->handle());
-#elif defined(OS_MACOSX) || defined(OS_ANDROID)
+#elif defined(OS_MACOSX) || defined(OS_ANDROID) || defined(OS_FREEBSD)
   return static_cast<intptr_t>(dib_->handle().fd);
 #elif defined(OS_POSIX)
   return static_cast<intptr_t>(dib_->handle());
