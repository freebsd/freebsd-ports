--- content/renderer/media/media_stream_dependency_factory_stub.cc.orig	2012-04-01 01:08:09.000000000 +0300
+++ content/renderer/media/media_stream_dependency_factory_stub.cc	2012-04-01 01:09:34.000000000 +0300
@@ -8,34 +8,40 @@
 
 MediaStreamDependencyFactory::~MediaStreamDependencyFactory() {}
 
-cricket::WebRtcMediaEngine*
-MediaStreamDependencyFactory::CreateWebRtcMediaEngine() {
-  return NULL;
-}
-
 bool MediaStreamDependencyFactory::CreatePeerConnectionFactory(
-    cricket::MediaEngineInterface* media_engine,
-    talk_base::Thread* worker_thread) {
+    talk_base::Thread* worker_thread,
+    talk_base::Thread* signaling_thread,
+    content::P2PSocketDispatcher* socket_dispatcher,
+    talk_base::NetworkManager* network_manager,
+    talk_base::PacketSocketFactory* socket_factory) {
   return false;
 }
 
-void MediaStreamDependencyFactory::DeletePeerConnectionFactory() {
-}
+void MediaStreamDependencyFactory::ReleasePeerConnectionFactory() {}
 
 bool MediaStreamDependencyFactory::PeerConnectionFactoryCreated() {
   return false;
 }
 
-cricket::PortAllocator* MediaStreamDependencyFactory::CreatePortAllocator(
-    content::P2PSocketDispatcher* socket_dispatcher,
-    talk_base::NetworkManager* network_manager,
-    talk_base::PacketSocketFactory* socket_factory,
-    const webkit_glue::P2PTransport::Config& config) {
+talk_base::scoped_refptr<webrtc::PeerConnectionInterface>
+    MediaStreamDependencyFactory::CreatePeerConnection(const std::string& config,
+                         webrtc::PeerConnectionObserver* observer) {
+  return NULL;
+}
+
+talk_base::scoped_refptr<webrtc::LocalMediaStreamInterface>
+    MediaStreamDependencyFactory::CreateLocalMediaStream(const std::string& label) {
+  return NULL;
+}
+
+talk_base::scoped_refptr<webrtc::LocalVideoTrackInterface>
+    MediaStreamDependencyFactory::CreateLocalVideoTrack(const std::string& label,
+                          cricket::VideoCapturer* video_device) {
   return NULL;
 }
 
-webrtc::PeerConnection* MediaStreamDependencyFactory::CreatePeerConnection(
-    cricket::PortAllocator* port_allocator,
-    talk_base::Thread* signaling_thread) {
+talk_base::scoped_refptr<webrtc::LocalAudioTrackInterface>
+    MediaStreamDependencyFactory::CreateLocalAudioTrack(const std::string& label,
+                          webrtc::AudioDeviceModule* audio_device) {
   return NULL;
 }
