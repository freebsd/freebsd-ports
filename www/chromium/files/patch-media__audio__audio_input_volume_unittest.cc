--- ./media/audio/audio_input_volume_unittest.cc.orig	2014-04-30 22:41:23.000000000 +0200
+++ ./media/audio/audio_input_volume_unittest.cc	2014-05-04 14:38:48.000000000 +0200
@@ -74,7 +74,7 @@
         params, device_id);
     EXPECT_TRUE(NULL != ais);
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
     // Some linux devices do not support our settings, we may fail to open
     // those devices.
     if (!ais->Open()) {
