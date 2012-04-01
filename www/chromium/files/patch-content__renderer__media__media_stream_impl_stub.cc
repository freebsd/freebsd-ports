--- content/renderer/media/media_stream_impl_stub.cc.orig	2012-04-01 01:08:49.000000000 +0300
+++ content/renderer/media/media_stream_impl_stub.cc	2012-04-01 01:09:17.000000000 +0300
@@ -16,7 +16,6 @@
     MediaStreamDependencyFactory* dependency_factory)
     : dependency_factory_(dependency_factory),
       media_stream_dispatcher_(media_stream_dispatcher),
-      media_engine_(NULL),
       p2p_socket_dispatcher_(p2p_socket_dispatcher),
       network_manager_(NULL),
       vc_manager_(vc_manager),
@@ -24,14 +23,11 @@
       message_loop_proxy_(base::MessageLoopProxy::current()),
       signaling_thread_(NULL),
       worker_thread_(NULL),
-      chrome_worker_thread_("Chrome_libJingle_WorkerThread"),
-      vcm_created_(false) {
+      chrome_worker_thread_("Chrome_libJingle_WorkerThread") {
 }
 
 MediaStreamImpl::~MediaStreamImpl() {
   DCHECK(!peer_connection_handler_);
-  if (dependency_factory_.get())
-    dependency_factory_->DeletePeerConnectionFactory();
 }
 
 WebKit::WebPeerConnectionHandler* MediaStreamImpl::CreatePeerConnectionHandler(
@@ -42,10 +38,6 @@
 void MediaStreamImpl::ClosePeerConnection() {
 }
 
-bool MediaStreamImpl::SetVideoCaptureModule(const std::string& label) {
-  return false;
-}
-
 void MediaStreamImpl::requestUserMedia(
     const WebKit::WebUserMediaRequest& user_media_request,
     const WebKit::WebVector<WebKit::WebMediaStreamSource>&
@@ -96,3 +88,8 @@
 
 void MediaStreamImpl::OnDeviceOpenFailed(int request_id) {
 }
+
+webrtc::MediaStreamTrackInterface* MediaStreamImpl::GetLocalMediaStreamTrack(
+    const std::string& label) {
+  return NULL;
+}
