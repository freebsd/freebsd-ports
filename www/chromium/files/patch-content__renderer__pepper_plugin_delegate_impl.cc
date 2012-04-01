--- content/renderer/pepper_plugin_delegate_impl.cc.orig	2012-02-21 10:34:09.000000000 +0200
+++ content/renderer/pepper_plugin_delegate_impl.cc	2012-02-27 18:05:36.000000000 +0200
@@ -124,7 +124,7 @@
         dib_(dib) {
   }
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
   // On Mac, we have to tell the browser to free the transport DIB.
   virtual ~PlatformImage2DImpl() {
     if (dib_.get()) {
@@ -142,7 +142,7 @@
     *byte_count = dib_->size();
 #if defined(OS_WIN)
     return reinterpret_cast<intptr_t>(dib_->handle());
-#elif defined(OS_MACOSX) || defined(OS_ANDROID)
+#elif defined(OS_MACOSX) || defined(OS_ANDROID) || defined(OS_FREEBSD)
     return static_cast<intptr_t>(dib_->handle().fd);
 #elif defined(OS_POSIX)
     return static_cast<intptr_t>(dib_->handle());
@@ -1208,7 +1208,7 @@
   uint32 buffer_size = width * height * 4;
 
   // Allocate the transport DIB and the PlatformCanvas pointing to it.
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
   // On the Mac, shared memory has to be created in the browser in order to
   // work in the sandbox.  Do this by sending a message to the browser
   // requesting a TransportDIB (see also
