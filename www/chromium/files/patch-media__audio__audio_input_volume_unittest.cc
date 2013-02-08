--- media/audio/audio_input_volume_unittest.cc.orig	2013-01-08 22:03:03.389246512 +0200
+++ media/audio/audio_input_volume_unittest.cc	2013-01-08 22:03:51.071246007 +0200
@@ -59,7 +59,7 @@
     int samples_per_packet = 0;
 #if defined(OS_MACOSX)
     samples_per_packet = (sample_rate / 100);
-#elif defined(OS_LINUX) || defined(OS_OPENBSD)
+#elif defined(OS_LINUX) || defined(OS_BSD)
     samples_per_packet = (sample_rate / 100);
 #elif defined(OS_WIN)
     if (sample_rate == 44100)
@@ -75,7 +75,7 @@
         device_id);
     EXPECT_TRUE(NULL != ais);
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
     // Some linux devices do not support our settings, we may fail to open
     // those devices.
     if (!ais->Open()) {
