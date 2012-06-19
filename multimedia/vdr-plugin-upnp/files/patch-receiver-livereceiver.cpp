--- a/receiver/livereceiver.cpp
+++ b/receiver/livereceiver.cpp
@@ -31,9 +31,19 @@ cLiveReceiver* cLiveReceiver::newInstanc
     }
 }
 
+#if (APIVERSNUM < 10725)
 cLiveReceiver::cLiveReceiver(cChannel *Channel, cDevice *Device)
 : cReceiver( Channel->GetChannelID(), 0, Channel->Vpid(), Channel->Apids(), Channel->Dpids(), Channel->Spids()),
   mDevice(Device), mChannel(Channel){
+#else
+cLiveReceiver::cLiveReceiver(cChannel *Channel, cDevice *Device)
+: cReceiver( Channel, 0),
+  mDevice(Device), mChannel(Channel){
+    AddPid(Channel->Vpid());
+    AddPids(Channel->Apids());
+    AddPids(Channel->Dpids());
+    AddPids(Channel->Spids());
+#endif
     this->mLiveBuffer = NULL;
     this->mOutputBuffer = NULL;
     this->mFrameDetector = NULL;
@@ -185,4 +195,4 @@ void cLiveReceiver::close(){
     delete this->mLiveBuffer; this->mLiveBuffer = NULL;
     this->mFrameDetector = NULL;
     MESSAGE(VERBOSE_LIVE_TV, "Live receiver closed.");
-}
\ No newline at end of file
+}
