--- media/audio/audio_output_proxy_unittest.cc.orig	2026-01-14 08:33:23 UTC
+++ media/audio/audio_output_proxy_unittest.cc
@@ -445,7 +445,11 @@ class AudioOutputProxyTest : public testing::Test {
     // |stream| is closed at this point. Start() should reopen it again.
     EXPECT_CALL(manager(), MakeAudioOutputStream(_, _, _))
         .Times(2)
+#if BUILDFLAG(IS_BSD)
+        .WillRepeatedly(Return(static_cast<AudioOutputStream*>(NULL)));
+#else
         .WillRepeatedly(Return(reinterpret_cast<AudioOutputStream*>(NULL)));
+#endif
 
     EXPECT_CALL(callback_, OnError(_)).Times(2);
 
