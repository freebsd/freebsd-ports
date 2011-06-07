--- content/renderer/pepper_plugin_delegate_impl.cc.orig	2011-05-06 12:02:55.000000000 +0300
+++ content/renderer/pepper_plugin_delegate_impl.cc	2011-06-04 14:31:17.879380898 +0300
@@ -112,7 +112,7 @@
         dib_(dib) {
   }
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
   // On Mac, we have to tell the browser to free the transport DIB.
   virtual ~PlatformImage2DImpl() {
     if (dib_.get()) {
@@ -130,7 +130,7 @@
     *byte_count = dib_->size();
 #if defined(OS_WIN)
     return reinterpret_cast<intptr_t>(dib_->handle());
-#elif defined(OS_MACOSX)
+#elif defined(OS_MACOSX) || defined(OS_FREEBSD)
     return static_cast<intptr_t>(dib_->handle().fd);
 #elif defined(OS_LINUX)
     return static_cast<intptr_t>(dib_->handle());
@@ -758,7 +758,7 @@
   uint32 buffer_size = width * height * 4;
 
   // Allocate the transport DIB and the PlatformCanvas pointing to it.
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
   // On the Mac, shared memory has to be created in the browser in order to
   // work in the sandbox.  Do this by sending a message to the browser
   // requesting a TransportDIB (see also
