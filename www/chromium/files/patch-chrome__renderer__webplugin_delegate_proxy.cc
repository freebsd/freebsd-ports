--- chrome/renderer/webplugin_delegate_proxy.cc.orig	Mon Mar 14 19:30:50 2011
+++ chrome/renderer/webplugin_delegate_proxy.cc	Mon Mar 14 19:39:56 2011
@@ -158,7 +158,7 @@ class ResourceClientProxy : public webkit::npapi::WebP
   bool multibyte_response_expected_;
 };
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_OPENBSD) || defined(OS_FREEBSD)
 static void ReleaseTransportDIB(TransportDIB* dib) {
   if (dib) {
     IPC::Message* message = new ViewHostMsg_FreeTransportDIB(dib->id());
@@ -184,7 +184,7 @@ WebPluginDelegateProxy::WebPluginDelegateProxy(
 }
 
 WebPluginDelegateProxy::~WebPluginDelegateProxy() {
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_OPENBSD) || defined(OS_FREEBSD)
   // Ask the browser to release old TransportDIB objects for which no
   // PluginHostMsg_UpdateGeometry_ACK was ever received from the plugin
   // process.
@@ -530,7 +530,7 @@ void WebPluginDelegateProxy::UpdateGeometry(const gfx:
   bool bitmaps_changed = false;
 
   PluginMsg_UpdateGeometry_Param param;
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_OPENBSD) || defined(OS_FREEBSD)
   param.ack_key = -1;
 #endif
 
@@ -542,7 +542,7 @@ void WebPluginDelegateProxy::UpdateGeometry(const gfx:
       bitmaps_changed = true;
 
       bool needs_background_store = transparent_;
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_OPENBSD) || defined(OS_FREEBSD)
       // We don't support transparency under QuickDraw, and CoreGraphics
       // preserves transparency information (and does the compositing itself)
       // so plugins don't need access to the page background.
@@ -614,7 +614,7 @@ void WebPluginDelegateProxy::UpdateGeometry(const gfx:
 }
 
 void WebPluginDelegateProxy::ResetWindowlessBitmaps() {
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_OPENBSD) || defined(OS_FREEBSD)
   DCHECK(!background_store_.get());
   // The Mac TransportDIB implementation uses base::SharedMemory, which
   // cannot be disposed of if an in-flight UpdateGeometry message refers to
@@ -675,12 +675,12 @@ bool WebPluginDelegateProxy::CreateSharedBitmap(
     scoped_ptr<TransportDIB>* memory,
     scoped_ptr<skia::PlatformCanvas>* canvas) {
   const size_t size = BitmapSizeForPluginRect(plugin_rect_);
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_OPENBSD) && !defined(OS_FREEBSD)
   memory->reset(TransportDIB::Create(size, 0));
   if (!memory->get())
     return false;
 #endif
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_OPENBSD) || defined(OS_FREEBSD)
   TransportDIB::Handle handle;
   IPC::Message* msg = new ViewHostMsg_AllocTransportDIB(size, true, &handle);
   if (!RenderThread::current()->Send(msg))
