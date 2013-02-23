--- media/audio/audio_low_latency_input_output_unittest.cc.orig	2013-02-05 10:01:14.000000000 +0200
+++ media/audio/audio_low_latency_input_output_unittest.cc	2013-02-13 19:58:04.000000000 +0200
@@ -19,7 +19,7 @@
 #include "testing/gmock/include/gmock/gmock.h"
 #include "testing/gtest/include/gtest/gtest.h"
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "media/audio/linux/audio_manager_linux.h"
 #elif defined(OS_MACOSX)
 #include "media/audio/mac/audio_manager_mac.h"
@@ -33,7 +33,7 @@
 
 namespace media {
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
 typedef AudioManagerLinux AudioManagerAnyPlatform;
 #elif defined(OS_MACOSX)
 typedef AudioManagerMac AudioManagerAnyPlatform;
