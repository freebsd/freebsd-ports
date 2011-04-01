--- chrome/renderer/pepper_plugin_delegate_impl.cc.orig	2011-03-23 00:45:32.195641203 +0200
+++ chrome/renderer/pepper_plugin_delegate_impl.cc	2011-03-23 00:45:48.140640079 +0200
@@ -48,7 +48,7 @@
 #include "webkit/plugins/ppapi/ppapi_plugin_instance.h"
 #include "webkit/plugins/ppapi/ppb_flash_impl.h"
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
 #include "chrome/common/render_messages.h"
 #include "chrome/renderer/render_thread.h"
 #endif
@@ -76,7 +76,7 @@
         dib_(dib) {
   }
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
   // On Mac, we have to tell the browser to free the transport DIB.
   virtual ~PlatformImage2DImpl() {
     if (dib_.get()) {
@@ -94,7 +94,7 @@
     *byte_count = dib_->size();
 #if defined(OS_WIN)
     return reinterpret_cast<intptr_t>(dib_->handle());
-#elif defined(OS_MACOSX)
+#elif defined(OS_MACOSX) || defined(OS_FREEBSD)
     return static_cast<intptr_t>(dib_->handle().fd);
 #elif defined(OS_LINUX)
     return static_cast<intptr_t>(dib_->handle());
@@ -494,7 +494,7 @@
   uint32 buffer_size = width * height * 4;
 
   // Allocate the transport DIB and the PlatformCanvas pointing to it.
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
   // On the Mac, shared memory has to be created in the browser in order to
   // work in the sandbox.  Do this by sending a message to the browser
   // requesting a TransportDIB (see also
