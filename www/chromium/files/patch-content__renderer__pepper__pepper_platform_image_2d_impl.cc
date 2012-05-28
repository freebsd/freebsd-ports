--- content/renderer/pepper/pepper_platform_image_2d_impl.cc.orig	2012-04-25 10:01:32.000000000 +0300
+++ content/renderer/pepper/pepper_platform_image_2d_impl.cc	2012-04-29 21:32:59.000000000 +0300
@@ -19,7 +19,7 @@
 
 // On Mac, we have to tell the browser to free the transport DIB.
 PepperPlatformImage2DImpl::~PepperPlatformImage2DImpl() {
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
   if (dib_.get()) {
     RenderThreadImpl::current()->Send(
         new ViewHostMsg_FreeTransportDIB(dib_->id()));
@@ -33,7 +33,7 @@
   uint32 buffer_size = width * height * 4;
 
   // Allocate the transport DIB and the PlatformCanvas pointing to it.
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
   // On the Mac, shared memory has to be created in the browser in order to
   // work in the sandbox.  Do this by sending a message to the browser
   // requesting a TransportDIB (see also
@@ -70,7 +70,7 @@
   *byte_count = dib_->size();
 #if defined(OS_WIN)
   return reinterpret_cast<intptr_t>(dib_->handle());
-#elif defined(OS_MACOSX) || defined(OS_ANDROID)
+#elif defined(OS_MACOSX) || defined(OS_ANDROID) || defined(OS_FREEBSD)
   return static_cast<intptr_t>(dib_->handle().fd);
 #elif defined(OS_POSIX)
   return static_cast<intptr_t>(dib_->handle());
