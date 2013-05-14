--- media/audio/audio_input_volume_unittest.cc.orig	2013-04-30 10:22:14.000000000 +0300
+++ media/audio/audio_input_volume_unittest.cc	2013-05-07 21:17:17.000000000 +0300
@@ -57,7 +57,7 @@
         params, device_id);
     EXPECT_TRUE(NULL != ais);
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
     // Some linux devices do not support our settings, we may fail to open
     // those devices.
     if (!ais->Open()) {
