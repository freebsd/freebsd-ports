--- media/audio/audio_low_latency_input_output_unittest.cc.orig	2013-01-08 22:05:58.175309674 +0200
+++ media/audio/audio_low_latency_input_output_unittest.cc	2013-01-08 22:06:40.328246386 +0200
@@ -19,7 +19,7 @@
 #include "testing/gmock/include/gmock/gmock.h"
 #include "testing/gtest/include/gtest/gtest.h"
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "media/audio/linux/audio_manager_linux.h"
 #elif defined(OS_MACOSX)
 #include "media/audio/mac/audio_manager_mac.h"
@@ -32,7 +32,7 @@
 
 namespace media {
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
 typedef AudioManagerLinux AudioManagerAnyPlatform;
 #elif defined(OS_MACOSX)
 typedef AudioManagerMac AudioManagerAnyPlatform;
@@ -338,7 +338,7 @@
 #if defined(OS_MACOSX)
     // 10ms buffer size works well for 44.1, 48, 96 and 192kHz.
     samples_per_packet_ = (sample_rate_ / 100);
-#elif defined(OS_LINUX) || defined(OS_OPENBSD)
+#elif defined(OS_LINUX) || defined(OS_BSD)
     // 10ms buffer size works well for 44.1, 48, 96 and 192kHz.
     samples_per_packet_ = (sample_rate_ / 100);
 #elif defined(OS_WIN)
